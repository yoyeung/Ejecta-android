/*
 * Copyright (C) 2006 Apple Computer, Inc.  All rights reserved.
 * Copyright (C) 2007 Alp Toker <alp@atoker.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#include "JSContextRef.h"
#include "JSNode.h"
#include "JSObjectRef.h"
#include "JSStringRef.h"
#include <stdio.h>
#include <stdlib.h>
#include <wtf/Assertions.h>
#include <wtf/UnusedParam.h>
#include <windows.h>

static char* createStringWithContentsOfFile(const char* fileName);
static JSValueRef print(JSContextRef context, JSObjectRef object, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

int main(int argc, char* argv[])
{
    JSGlobalContextRef context;
    JSObjectRef globalObject;
    JSStringRef printIString;
    JSStringRef node;
    char* scriptUTF8;
    JSStringRef script;
    JSValueRef exception;
    JSValueRef result;

    const char *scriptPath = "minidom.js";
    if (argc > 1) {
        scriptPath = argv[1];
    }

    context = JSGlobalContextCreateInGroup(NULL, NULL);
    globalObject = JSContextGetGlobalObject(context);
    
    printIString = JSStringCreateWithUTF8CString("print");
    JSObjectSetProperty(context, globalObject, printIString, JSObjectMakeFunctionWithCallback(context, printIString, print), kJSPropertyAttributeNone, NULL);
    JSStringRelease(printIString);
    
    node = JSStringCreateWithUTF8CString("Node");
    JSObjectSetProperty(context, globalObject, node, JSObjectMakeConstructor(context, JSNode_class(context), JSNode_construct), kJSPropertyAttributeNone, NULL);
    JSStringRelease(node);
    
    scriptUTF8 = createStringWithContentsOfFile(scriptPath);
    script = JSStringCreateWithUTF8CString(scriptUTF8);
    exception;
    result = JSEvaluateScript(context, script, NULL, NULL, 1, &exception);
    if (result)
        printf("PASS: Test script executed successfully.\n");
    else {
        JSStringRef exceptionIString = JSValueToStringCopy(context, exception, NULL);
        size_t exceptionUTF8Size = JSStringGetMaximumUTF8CStringSize(exceptionIString);
        char* exceptionUTF8 = (char*)malloc(exceptionUTF8Size);
        printf("FAIL: Test script threw exception:\n");
        JSStringGetUTF8CString(exceptionIString, exceptionUTF8, exceptionUTF8Size);
        printf("%s\n", exceptionUTF8);
        free(exceptionUTF8);
        JSStringRelease(exceptionIString);
    }
    JSStringRelease(script);
    free(scriptUTF8);

    globalObject = 0;
    JSGlobalContextRelease(context);
    printf("PASS: Program exited normally.\n");
    
    return 0;
}

// utf8 to gbk
int UTF8ToGBK(unsigned char * lpUTF8Str,unsigned char * lpGBKStr,int nGBKStrLen)
{
    wchar_t * lpUnicodeStr = NULL;
    int nRetLen = 0;
    if(!lpUTF8Str)
        return 0;
    nRetLen = MultiByteToWideChar(CP_UTF8,0,(char *)lpUTF8Str,-1,0,0);
    lpUnicodeStr = (WCHAR*)malloc(sizeof(WCHAR)*(nRetLen + 1));
    nRetLen = MultiByteToWideChar(CP_UTF8,0,(char *)lpUTF8Str,-1,lpUnicodeStr,nRetLen);
    if(!nRetLen)
        return 0;
    nRetLen = WideCharToMultiByte(CP_ACP,0,lpUnicodeStr,-1,0,0,0,0);
    if(!lpGBKStr)
    {
        if(lpUnicodeStr)
            free(lpUnicodeStr);
        return nRetLen;
    }
    if(nGBKStrLen < nRetLen)
    {
        if(lpUnicodeStr)
            free(lpUnicodeStr);
        return 0;
    }
    nRetLen = WideCharToMultiByte(CP_ACP,0,lpUnicodeStr,-1,(char *)lpGBKStr,nRetLen,0,0);
    if(lpUnicodeStr)
        free(lpUnicodeStr);
    return nRetLen;
}

static JSValueRef print(JSContextRef context, JSObjectRef object, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
{
    UNUSED_PARAM(object);
    UNUSED_PARAM(thisObject);

    if (argumentCount > 0) {
        JSStringRef string = JSValueToStringCopy(context, arguments[0], exception);
        size_t numChars = JSStringGetMaximumUTF8CStringSize(string);
        char* stringUTF8 = (char*)malloc(numChars*sizeof(char));
        char* stringGBK;
        JSStringGetUTF8CString(string, stringUTF8, numChars);
        stringGBK = (char*)malloc(numChars*sizeof(char)*6);
        UTF8ToGBK(stringUTF8, stringGBK, numChars*sizeof(char)*6);
        printf("%s\n", stringGBK);
        free(stringUTF8);
        free(stringGBK);
    }
    
    return JSValueMakeUndefined(context);
}

static char* createStringWithContentsOfFile(const char* fileName)
{
    char* buffer;
    FILE* f;
    size_t buffer_size = 0;
    size_t buffer_capacity = 1024;
    buffer = (char*)malloc(buffer_capacity);
    
    f = fopen(fileName, "r");
    if (!f) {
        fprintf(stderr, "Could not open file: %s\n", fileName);
        return 0;
    }
    
    while (!feof(f) && !ferror(f)) {
        buffer_size += fread(buffer + buffer_size, 1, buffer_capacity - buffer_size, f);
        if (buffer_size == buffer_capacity) { /* guarantees space for trailing '\0' */
            buffer_capacity *= 2;
            buffer = (char*)realloc(buffer, buffer_capacity);
            ASSERT(buffer);
        }
        
        ASSERT(buffer_size < buffer_capacity);
    }
    fclose(f);
    buffer[buffer_size] = '\0';
    
    return buffer;
}

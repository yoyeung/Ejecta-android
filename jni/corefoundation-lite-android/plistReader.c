/*
Code from: http://developer.apple.com/opensource/cflite.html
*/

#include <CoreFoundation/CoreFoundation.h>

void readPropertyListFromFile( void );

const char * kFilename = "param.plist";

int main ( int argc, const char * argv[] ) {
  // Read the plist.
  readPropertyListFromFile();

  return 0;
}

void readPropertyListFromFile( void ) {
  CFDataRef data = NULL;
  
  FILE *file = fopen( kFilename, "r" );

  if ( file != NULL ) {
    printf("file opened");
    int result = fseek( file, 0, SEEK_END );
    result = ftell( file );
    rewind( file );

    char * buffer = ( char * )calloc( 1, result );

    if ( buffer != NULL ) {
      if ( fread( buffer, result, 1, file ) > 0 ) {
	printf("buffer read");
	data = CFDataCreate( NULL, buffer, result );
      }

      free( buffer );
    } 

    fclose( file );
  }

  if ( data != NULL ) {
    CFPropertyListRef propertyList = CFPropertyListCreateFromXMLData( NULL, data,
								      kCFPropertyListImmutable, NULL );

    CFShow( CFSTR( "Property list (as read from file):" ) );
    CFShow( propertyList );
  }

  if ( data ) {
      CFRelease( data );
  }
}

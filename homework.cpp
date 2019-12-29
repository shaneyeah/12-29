using namespace std;
#include "String.h"
int main()
{
String s1( "happy" );
String s2( " birthday" );
// member functions
s1.show(); // show string content
s1.cat(s2); // append s2 to s1
s1.show(); // show string content
s1.show(5,3); // show substring from location 5
return 0;
} // end main

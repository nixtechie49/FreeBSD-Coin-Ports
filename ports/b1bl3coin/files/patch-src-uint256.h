--- src/uint256.h.orig	2014-11-01 19:13:35 UTC
+++ src/uint256.h
@@ -342,12 +342,12 @@ public:
     }
 
     unsigned char* begin()
-    {
+    const {
         return (unsigned char*)&pn[0];
     }
 
     unsigned char* end()
-    {
+    const {
         return (unsigned char*)&pn[WIDTH];
     }
 

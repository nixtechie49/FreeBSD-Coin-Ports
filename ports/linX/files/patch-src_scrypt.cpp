--- src/scrypt.cpp.orig	2017-06-01 16:52:17 UTC
+++ src/scrypt.cpp
@@ -44,22 +44,6 @@
 #endif
 #endif
 
-static inline uint32_t be32dec(const void *pp)
-{
-	const uint8_t *p = (uint8_t const *)pp;
-	return ((uint32_t)(p[3]) + ((uint32_t)(p[2]) << 8) +
-	    ((uint32_t)(p[1]) << 16) + ((uint32_t)(p[0]) << 24));
-}
-
-static inline void be32enc(void *pp, uint32_t x)
-{
-	uint8_t *p = (uint8_t *)pp;
-	p[3] = x & 0xff;
-	p[2] = (x >> 8) & 0xff;
-	p[1] = (x >> 16) & 0xff;
-	p[0] = (x >> 24) & 0xff;
-}
-
 typedef struct HMAC_SHA256Context {
 	SHA256_CTX ictx;
 	SHA256_CTX octx;

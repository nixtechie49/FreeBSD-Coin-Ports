--- src/serialize.h.orig	2014-12-29 16:35:22 UTC
+++ src/serialize.h
@@ -811,19 +811,6 @@ public:
     iterator insert(iterator it, const char& x=char()) { return vch.insert(it, x); }
     void insert(iterator it, size_type n, const char& x) { vch.insert(it, n, x); }
 
-    void insert(iterator it, const_iterator first, const_iterator last)
-    {
-        assert(last - first >= 0);
-        if (it == vch.begin() + nReadPos && (unsigned int)(last - first) <= nReadPos)
-        {
-            // special case for inserting at the front when there's room
-            nReadPos -= (last - first);
-            memcpy(&vch[nReadPos], &first[0], last - first);
-        }
-        else
-            vch.insert(it, first, last);
-    }
-
     void insert(iterator it, std::vector<char>::const_iterator first, std::vector<char>::const_iterator last)
     {
         assert(last - first >= 0);
@@ -855,6 +842,7 @@ public:
     iterator erase(iterator it)
     {
         if (it == vch.begin() + nReadPos)
+
         {
             // special case for erasing from the front
             if (++nReadPos >= vch.size())

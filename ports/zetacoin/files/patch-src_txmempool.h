--- src/txmempool.h.orig	2018-04-15 19:48:38 UTC
+++ src/txmempool.h
@@ -201,7 +201,7 @@ struct mempoolentry_txid
 class CompareTxMemPoolEntryByDescendantScore
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         bool fUseADescendants = UseDescendantScore(a);
         bool fUseBDescendants = UseDescendantScore(b);
@@ -223,7 +223,7 @@ public:
     }
 
     // Calculate which score to use for an entry (avoiding division).
-    bool UseDescendantScore(const CTxMemPoolEntry &a)
+    bool UseDescendantScore(const CTxMemPoolEntry &a) const
     {
         double f1 = (double)a.GetModifiedFee() * a.GetSizeWithDescendants();
         double f2 = (double)a.GetModFeesWithDescendants() * a.GetTxSize();
@@ -238,7 +238,7 @@ public:
 class CompareTxMemPoolEntryByScore
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         double f1 = (double)a.GetModifiedFee() * b.GetTxSize();
         double f2 = (double)b.GetModifiedFee() * a.GetTxSize();
@@ -252,7 +252,7 @@ public:
 class CompareTxMemPoolEntryByEntryTime
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         return a.GetTime() < b.GetTime();
     }

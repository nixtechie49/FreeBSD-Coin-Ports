--- src/rpcserver.cpp.orig	2015-04-13 15:44:29 UTC
+++ src/rpcserver.cpp
@@ -528,8 +528,8 @@ private:
 void ServiceConnection(AcceptedConnection *conn);
 
 // Forward declaration required for RPCListen
-template <typename Protocol, typename SocketAcceptorService>
-static void RPCAcceptHandler(boost::shared_ptr< basic_socket_acceptor<Protocol, SocketAcceptorService> > acceptor,
+template <typename Protocol>
+static void RPCAcceptHandler(boost::shared_ptr< basic_socket_acceptor<Protocol> > acceptor,
                              ssl::context& context,
                              bool fUseSSL,
                              boost::shared_ptr< AcceptedConnection > conn,
@@ -538,8 +538,8 @@ static void RPCAcceptHandler(boost::shar
 /**
  * Sets up I/O resources to accept and handle a new connection.
  */
-template <typename Protocol, typename SocketAcceptorService>
-static void RPCListen(boost::shared_ptr< basic_socket_acceptor<Protocol, SocketAcceptorService> > acceptor,
+template <typename Protocol>
+static void RPCListen(boost::shared_ptr< basic_socket_acceptor<Protocol> > acceptor,
                    ssl::context& context,
                    const bool fUseSSL)
 {
@@ -549,7 +549,7 @@ static void RPCListen(boost::shared_ptr<
     acceptor->async_accept(
             conn->sslStream.lowest_layer(),
             conn->peer,
-            boost::bind(&RPCAcceptHandler<Protocol, SocketAcceptorService>,
+            boost::bind(&RPCAcceptHandler<Protocol>,
                 acceptor,
                 boost::ref(context),
                 fUseSSL,
@@ -561,8 +561,8 @@ static void RPCListen(boost::shared_ptr<
 /**
  * Accept and handle incoming connection.
  */
-template <typename Protocol, typename SocketAcceptorService>
-static void RPCAcceptHandler(boost::shared_ptr< basic_socket_acceptor<Protocol, SocketAcceptorService> > acceptor,
+template <typename Protocol>
+static void RPCAcceptHandler(boost::shared_ptr< basic_socket_acceptor<Protocol> > acceptor,
                              ssl::context& context,
                              const bool fUseSSL,
                              boost::shared_ptr< AcceptedConnection > conn,
@@ -629,7 +629,7 @@ void StartRPCThreads()
 
     assert(rpc_io_service == NULL);
     rpc_io_service = new asio::io_service();
-    rpc_ssl_context = new ssl::context(*rpc_io_service, ssl::context::sslv23);
+    rpc_ssl_context = new ssl::context(ssl::context::sslv23);
 
     const bool fUseSSL = GetBoolArg("-rpcssl", false);
 
@@ -648,7 +648,7 @@ void StartRPCThreads()
         else LogPrintf("ThreadRPCServer ERROR: missing server private key file %s\n", pathPKFile.string());
 
         string strCiphers = GetArg("-rpcsslciphers", "TLSv1.2+HIGH:TLSv1+HIGH:!SSLv2:!aNULL:!eNULL:!3DES:@STRENGTH");
-        SSL_CTX_set_cipher_list(rpc_ssl_context->impl(), strCiphers.c_str());
+        SSL_CTX_set_cipher_list(rpc_ssl_context->native_handle(), strCiphers.c_str());
     }
 
     // Try a dual IPv6/IPv4 socket, falling back to separate IPv4 and IPv6 sockets

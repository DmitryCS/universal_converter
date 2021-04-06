#include "udecoder/dummy.h"
#include <iostream>
#include "csv.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/StreamCopier.h"
#include <unordered_map>
#include <algorithm>
#include "Poco/Net/HTMLForm.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPSessionInstantiator.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/Net.h";
#include "Poco/Util/Util.h";
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Application.h"
#include "Poco/Process.h"

using namespace Poco::Util;
using namespace Poco::Net;
class RootHandler : public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request,
		Poco::Net::HTTPServerResponse& response)
	{
		response.setChunkedTransferEncoding(true);
		response.setContentType("text/html");
		std::ostream& ostr = response.send();		
		ostr << "<html><head><title>HTTP Server powered by POCO C++ Libraries</title></head>";
		ostr << "<body>";		
		ostr << "<h1>Hello world</h1>";
		ostr << "</body></html>";
	}
};


class MyRequestHandlerFactory : public
	Poco::Net::HTTPRequestHandlerFactory
{
public:
	MyRequestHandlerFactory()
	{
	}
	Poco::Net::HTTPRequestHandler* createRequestHandler(
		const Poco::Net::HTTPServerRequest& request)
	{		
		//if (request.getURI() == "/")
		return new RootHandler();
		//else
		//	return new DataHandler();
	}
};

int main()
{
	//std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> ump;	

	//std::cout << "85496736897 + 94583068 = "
	//	<< udecoder::sum("85496736897", "94583068")
	//	<< std::endl;
	if (__argc > 1) {
		std::cout << __argc << " " << __argv[2] << std::endl;		
	}	
	io::CSVReader<3> in("rules.csv");
	in.read_header(io::ignore_extra_column, "S", "T", "value");
	std::string S; std::string T; double value;
	while (in.read_row(S, T, value)) {
		S.erase(remove_if(S.begin(), S.end(), isspace), S.end());
		T.erase(remove_if(T.begin(), T.end(), isspace), T.end());		
		//ump[S].push_back({ T,value });
		//ump[T].push_back({ S,1/value });
		std::cout << S << " " << T << " " << value << " " << std::endl;
	}
	//Poco::Net::ServerSocket srv(8080); // does bind + listen

	Poco::UInt16 port = 9998;
	HTTPServerParams* pParams = new HTTPServerParams;
	pParams->setMaxQueued(100);
	pParams->setMaxThreads(16);
	ServerSocket svs(port); // set-up a server socket
	HTTPServer srv(new MyRequestHandlerFactory(), svs, pParams);
	// start the HTTPServer
	srv.start();
	Sleep(1000000);
	//Poco::Util::Application::waitForTerminationRequest();
	//Poco::Util::ServerApplication::waitForTerminationRequest();
	// Stop the HTTPServer
	srv.stop();

	//auto x = MyRequestHandlerFactory();
	//x.createRequestHandler()
	//for (;;)
	//{
	//	Poco::Net::StreamSocket ss = srv.acceptConnection();
	//
	//	char t;
	//	std::string tt;

	//	Poco::Net::SocketStream str(ss);
	//	//while (str >> t)std::cout << t;
	//	int nn = 55;
	//	while (nn--) {
	//		str >> tt;
	//		std::cout << tt << std::endl;
	//	}
	//	str << "HTTP/1.0 200 OK\r\n"
	//		"Content-Type: text/html\r\n"
	//		"\r\n"
	//		"<html><head><title>My 1st Web Server</title></head>"
	//		"<body><h1>Hello, world!</h1></body></html>"
	//		<< std::flush;
	//}
	return 0;
}
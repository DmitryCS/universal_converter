#include "udecoder/dummy.h"
#include <iostream>
#include "csv.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/StreamCopier.h"

int main()
{
	std::cout << "85496736897 + 94583068 = "
		<< udecoder::sum("85496736897", "94583068")
		<< std::endl;
	if (__argc > 1) {
		std::cout << __argc << " " << __argv[2] << std::endl;		
	}	
	io::CSVReader<3> in("rules.csv");
	in.read_header(io::ignore_extra_column, "S", "T", "value");
	std::string S; std::string T; double value;
	while (in.read_row(S, T, value)) {
		// do stuff with the data
		std::cout << S << " " << T << " " << value << " " << std::endl;

	}
	//Poco::Net::SocketAddress address("localhost", 80);
	//Poco::Net::SocketAddress sa("www.appinf.com", 80);
	//Poco::Net::StreamSocket socket(sa);
	//Poco::Net::SocketStream str(socket);
	//str << "GET / HTTP/1.1\r\n"
	//	"Host: www.appinf.com\r\n"
	//	"\r\n";
	//str.flush();
	//Poco::StreamCopier::copyStream(str, std::cout);

	return 0;
}

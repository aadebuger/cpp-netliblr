#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
// #include <network/uri.hpp>
#include <boost/program_options.hpp>
#include <boost/network/protocol/http.hpp>
int main( void )
{
      using namespace boost::network;
    std::error_code ec;
  network::uri uri = network::make_uri("I am not a valid URI.", ec);
    
    printf("hello\n");
    std::cout <<"aa"<<std::endl;
    
    std::string source = "http://www.baidu.com";
//    bool show_headers = options.count("headers") ? true : false;
//    bool show_status = options.count("status") ? true : false;
    
    http::client::request request(source);
    http::client::string_type destination_ = host(request);
    
    request << ::boost::network::header("Connection", "close");
    http::client::options client_options;
    client_options.follow_redirects(true);
    http::client client(client_options);
    http::client::response response = client.get(request);
    
    if (1)
        std::cout << status(response) << " " << status_message(response)
        << std::endl;
    
    if (1) {
        auto headers_ = response.headers();
        for (auto const& header : headers_) {
            std::cout << header.first << ": " << header.second << std::endl;
        }
        std::cout << std::endl;
    }
    
    std::cout << body(response);
    return EXIT_SUCCESS;

  
}

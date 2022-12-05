#include <link>
#include <iostream>

int main() {
	Link http(3000);

  	// 404 Page
  	http.Error(404, [](Request* req, Response* res) {
    	res->SetHTTP("HTTP/1.1 404 Not Found\r\n\r\n404 Not Found");
  	});
  	http.Default([](Request* req, Response* res) {
    	res->Error(404);
  	});
  
  	// Landing Page
  	http.Get("/", [](Request* req, Response* res) {
    	res->SetHeader("Content-Type", "text/html; charset=UTF-8");
    	res->SendFile("www/index.html");
  	});

  	http.Get("/css/style.css", [](Request* req, Response* res) {
   	 res->SetHeader("Content-Type", "text/css; charset=UTF-8");
  	  res->SendFile("www/css/index.css");
  	});

	std::cout << "gitserv started on port 3000." << std::endl;
  	http.Start();
}

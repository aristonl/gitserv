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

  	http.Get("/css/index.css", [](Request* req, Response* res) {
   	 res->SetHeader("Content-Type", "text/css; charset=UTF-8");
  	  res->SendFile("www/css/index.css");
  	});

	http.Get("/css/fonts.css", [](Request* req, Response* res) {
		res->SetHeader("Content-Type", "text/css; charset=UTF-8");
		res->SendFile("www/css/fonts.css");
	});

	// repository page
	http.Get("/aristonl/gitserv", [](Request* req, Response* res) {
		res->SetHeader("Content-Type", "text/html; charset=UTF-8");
		res->SendFile("www/repository.html");
	});

	// assets
	http.Get("/assets/img/n11-sm-white.svg", [](Request* req, Response* res) {
		res->SetHeader("Content-Type", "image/svg+xml");
		res->SendFile("www/assets/img/n11_sm_white.svg");
	});

	http.Get("/assets/fonts/JetBrainsMono-Italic-VariableFont_wght.ttf", 
			[](Request* req, Response* res) {
		res->SetHeader("Content-Type", "font/ttf");
		res->SendFile("www/assets/fonts/JetBrainsMono-Italic-VariableFont_wght.ttf");
	});

	http.Get("/assets/fonts/JetBrainsMono-VariableFont_wght.ttf", 
			[](Request* req, Response* res) {
		res->SetHeader("Content-Type", "font/ttf");
		res->SendFile("www/assets/fonts/JetBrainsMono-VariableFont_wght.ttf");
	});

	std::cout << "gitserv started on port 3000." << std::endl;
  	http.Start();
}

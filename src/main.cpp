#include <gitserv.h>
#include <iostream>
#include <fstream>
#include <Link.hpp>

#include <cstring>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // FIXME: init() is causing the web server to give 404's
	//init();

	Link::Server server;
	server.SetPort(3000);

	// 404 Page
	server.Error(404, [](Link::Request* req, Link::Response* res) {
		res->SetStatus(404)->SetBody("404 Not Found");
	});

	// Landing Page
	server.Get("/", [](Link::Request* req, Link::Response* res) {
		res->SetHeader("Content-Type", "text/html; charset=UTF-8");
		std::ifstream file("../www/index.html");
		std::string content((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());
		res->SetBody(content);
	});

	
	server.Get("/repos", [](Link::Request* req, Link::Response* res) {
		res->SetHeader("Content-Type", "text/html; charset=UTF-8");
		std::ifstream file("../www/repolist.html");
		std::string content((std::istreambuf_iterator<char>(file)),
				std::istreambuf_iterator<char>());
		res->SetBody(content);
	});

	server.Get("/mailinglists", [](Link::Request* req, Link::Response* res) {
		res->SetHeader("Content-Type", "text/html; charset=UTF-8");
		std::ifstream file("../www/mailinglists.html");
		std::string content((std::istreambuf_iterator<char>(file)),
				std::istreambuf_iterator<char>());
		res->SetBody(content);
	});

	server.Get("/aristonl/gitserv", [](Link::Request* req, Link::Response* res) {
		res->SetHeader("Content-Type", "text/html; charset=UTF-8");
		std::ifstream file("../www/repository.html");
		std::string content((std::istreambuf_iterator<char>(file)),
				std::istreambuf_iterator<char>());
		res->SetBody(content);
	});

	// TODO: maybe look into moving assets into public/?
	server.SetStaticPages("../www/");

	std::cout << "gitserv started on port 3000." << std::endl;
	server.Start();
}

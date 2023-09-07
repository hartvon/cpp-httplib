#include <httplib.h>

int main(void)
{
  httplib::Client cli("127.0.0.1", 8081);

  if (auto res = cli.Get("/hi")) {
    std::cout << res->status << "\n"
              << res->get_header_value("Content-Type") << "\n"
              << res->body << std::endl;
  }

  return 0;
}

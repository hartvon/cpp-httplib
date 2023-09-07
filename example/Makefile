CXX = g++
CXXFLAGS = -O1 -g -std=c++11 -I.. -Wall -Wextra -pthread

PREFIX = /usr/local

OPENSSL_DIR = $(PREFIX)/ssl
#OPENSSL_SUPPORT = -DCPPHTTPLIB_OPENSSL_SUPPORT -I$(OPENSSL_DIR)/include -L$(OPENSSL_DIR)/lib -lssl -lcrypto

ifneq ($(OS), Windows_NT)
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Darwin)
		OPENSSL_SUPPORT += -framework CoreFoundation -framework Security
	endif
endif

ZLIB_SUPPORT = -DCPPHTTPLIB_ZLIB_SUPPORT -lz

BROTLI_DIR = $(PREFIX)/brotli
#BROTLI_SUPPORT = -DCPPHTTPLIB_BROTLI_SUPPORT -I$(BROTLI_DIR)/include -L$(BROTLI_DIR)/lib -lbrotlicommon -lbrotlienc -lbrotlidec

BIN = bin

EXES = server client hello simplecli simplesvr upload redirect ssesvr ssecli benchmark issue
all: $(EXES)

server : server.cc ../httplib.h Makefile
	$(CXX) -o $(BIN)/$@ $(CXXFLAGS) server.cc $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT)

client : client.cc ../httplib.h Makefile
	$(CXX) -o $(BIN)/$@ $(CXXFLAGS) client.cc $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT)

hello : hello.cc ../httplib.h Makefile
	$(CXX) -o $(BIN)/$@ $(CXXFLAGS) hello.cc $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT)

simplecli : simplecli.cc ../httplib.h Makefile
	$(CXX) -o $(BIN)/$@ $(CXXFLAGS) simplecli.cc $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT)

simplesvr : simplesvr.cc ../httplib.h Makefile
	$(CXX) -o $(BIN)/$@ $(CXXFLAGS) simplesvr.cc $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT)

upload : upload.cc ../httplib.h Makefile
	$(CXX) -o $(BIN)/$@ $(CXXFLAGS) upload.cc $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT)

redirect : redirect.cc ../httplib.h Makefile
	$(CXX) -o $(BIN)/$@ $(CXXFLAGS) redirect.cc $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT)

ssesvr : ssesvr.cc ../httplib.h Makefile
	$(CXX) -o $(BIN)/$@ $(CXXFLAGS) ssesvr.cc $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT)

ssecli : ssecli.cc ../httplib.h Makefile
	$(CXX) -o $(BIN)/$@ $(CXXFLAGS) ssecli.cc $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT)

benchmark : benchmark.cc ../httplib.h Makefile
	$(CXX) -o $(BIN)/$@ $(CXXFLAGS) benchmark.cc $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT)

pem:
	openssl genrsa 2048 > key.pem
	openssl req -new -key key.pem | openssl x509 -days 3650 -req -signkey key.pem > cert.pem

clean:
# rm server client hello simplecli simplesvr upload redirect ssesvr ssecli benchmark *.pem
	rm $(BIN)/*  *.pem
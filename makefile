LD_PATH = -L/usr/local/lib -Wl,-rpath=/usr/local/lib

all: challenge10


challenge10:
	if [ -e challenge10 ]; then rm challenge10; fi
	g++ challenge10.cpp -I/usr/local/include $(LD_PATH) -lboost_regex -std=c++1y  -o challenge10	
	./challenge10
all:
	cd build && conan install .. && cmake . && make
install:
	cp build/bin/headtable /usr/local/bin/

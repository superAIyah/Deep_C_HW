prepare:
	sudo apt update -y
	sudo apt install -y cppcheck clang-tidy python3-pip libc6-dbg cmake libgtest-dev
	sudo apt install lcov
	./cmk
test:
	./build/tests/tests_lib
main:
	./build/main
check:
	./linter/run.sh
valgrind_install:
	wget https://sourceware.org/pub/valgrind/valgrind-3.18.1.tar.bz2
	tar xfv valgrind-3.18.1.tar.bz2
	cd valgrind-3.18.1
	./autogen.sh
	./configure
	make
	make install
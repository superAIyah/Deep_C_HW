prepare:
	sudo apt update -y
	sudo apt install -y cppcheck clang-tidy python3-pip libc6-dbg cmake libgtest-dev
	sudo apt install lcov
	./cmk
test:
	./build/tests/tests_lib
main:
	./build/main
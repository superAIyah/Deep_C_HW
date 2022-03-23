prepare:
	sudo apt update -y
	sudo apt install -y cppcheck clang-tidy python3-pip libc6-dbg cmake libgtest-dev
	sudo pip install cpplint
	sudo apt install lcov
	./script
check:
	./linters/run.sh
test:
	./build/tests/test_fib
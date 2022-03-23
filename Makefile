prepare:
	sudo apt update -y
	sudo apt install -y cppcheck clang-tidy python3-pip libc6-dbg cmake libgtest-dev
	sudo pip install cpplint
	./script
check:
	./linters/run.sh
test:
	./build/tests/test_fib
report:
	cd build/
	lcov -t "tests/test_funcs" -o coverage.info -c -d funcs/
	genhtml -o report coverage.info
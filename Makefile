check:
	./linters/run.sh
test:
	./script
	./build/tests/test_fib
	
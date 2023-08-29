clean:
	rm -f *.out

run-cpp11: clean
	g++ -std=c++11 -DCPP11 main.cpp runtimeFactorial.cpp -o program.out && ./program.out

run-cpp14: clean
	g++ -std=c++14 -DCPP14 main.cpp runtimeFactorial.cpp -o program.out && ./program.out

run-cpp17: clean
	g++ -std=c++17 -DCPP17 main.cpp runtimeFactorial.cpp -o program.out

run-cpp20: clean
	g++ -std=c++20 -DCPP20 main.cpp runtimeFactorial.cpp -o program.out
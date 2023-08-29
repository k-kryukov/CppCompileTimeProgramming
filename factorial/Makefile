all: run-cpp11 run-cpp14 run-cpp20 clean

clean:
	rm -f *.out

run-cpp11: clean
	g++ -std=c++11 -DCPP11 main.cpp runtimeFactorial.cpp -o program.out && ./program.out

run-cpp14: clean
	g++ -std=c++14 -DCPP14 main.cpp runtimeFactorial.cpp -o program.out && ./program.out

run-cpp17: clean
	echo "No specific code for cpp17"

run-cpp20: clean
	g++ -std=c++20 -DCPP20 main.cpp runtimeFactorial.cpp -o program.out && ./program.out
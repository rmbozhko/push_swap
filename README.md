Program usge:
If you would like to sort some ints, you can pass them easily, like so:
./push_swap [int_sequence]
push_swap will genrate steps to sort passed elements using two stacks.
Then gotten instructions can be passed to ./checker program, like so:
./checker [int_sequence]
or
./push_swap [int_sequence] | ./checker [int_sequence]
./checker retrieve instructions how to sort int_sequence and returns "OK" if 1-st is sorted, "KO" otherwise.
It is also possible to specify additional source of int_sequence for push_swap:
./push_swap [int_sequence] -istream ints.txt
, also there is a flag to specify the output fd for instructios:
./push_swap -istream ints.txt [int_sequence] -ostream res.txt
Important to know, at the beginning of 1-st stack int_sequence will be found. The content of ints.txt will be joined at the end. It doesn't matter what comes earlier as cmd arg.
Checker knows nothing about such possibility of push_swap. His -istream will parse instructions and -ostream will handle output like: "OK" || "KO" || "Error".
That is why the one should specify cmd var - A="[ints]" or pass all digits(from ints.txt and console) together in correct order. Console ones at the beginning, then file ones.

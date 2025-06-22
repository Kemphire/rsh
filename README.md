# RSH -> russian shell

# Instruction to build it

## For nix users

ahh, you guys most prolly know the method to build nix flakes

``sh
nix build
./result/bin/rsh
``

## For non-nix unix/linux users

``sh
cd build
cmake ..
make
``

## TODO

- [ ] fix the fucking cd bug, it is becoming pain in the ass
- [ ] fix all the fucking valgrind warnings
- [ ] implement input redirection
- [ ] implement clear command
- [ ] implement pipes
- [ ] implement support for parralel command
- [ ] start utilizing some good parsing algorithm to handle complex mixture of
operator, args and command

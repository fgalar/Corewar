rm *.cor *.corbis
make
cp ../tmp/*.s .
../tmp/asmexample car.s
../tmp/asmexample jumper.s
../tmp/asmexample kitty.s
../tmp/asmexample machine.s
../tmp/asmexample misaka.s
../tmp/asmexample skynet.s
../tmp/asmexample superkitty.s
../tmp/asmexample zork.s

./asm car.s
./asm jumper.s
./asm kitty.s
./asm machine.s
./asm misaka.s
./asm skynet.s
./asm superkitty.s
./asm zork.s

cmp -b car.cor car.corbis
cmp -b jumper.cor jumper.corbis
cmp -b kitty.cor kitty.corbis
cmp -b machine.cor machine.corbis
cmp -b misaka.cor misaka.corbis
cmp -b skynet.cor skynet.corbis
cmp -b superkitty.cor superkitty.corbis
cmp -b zork.cor zork.corbis

rm *.s *.corbis *.cor

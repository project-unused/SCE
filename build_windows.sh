x86_64-w64-mingw32-g++ ./$1 -static-libstdc++ -static-libgcc $2 $3 $4 $5 $6 $7 $8 $9 -o ./amd/bin/SCE.exe
i686-w64-mingw32-g++ ./$1 -static-libstdc++ -static-libgcc $2 $3 $4 $5 $6 $7 $8 $9 -o ./i386/bin/SCE.exe
#arm-none-eabi-gcc ./$1 -static-libstdc++ -static-libgcc $2 $3 $4 $5 $6 $7 $8 $9 -o SCE_Win_arm64.exe
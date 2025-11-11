Esté codigo foi escrito em linguagem C. 
foi construído em computador Aspire 5. com OS, Ubuntu 24.04

Instalação do OpenCV:
sudo apt install libopenv-dev

Compilação do programa:
g++ openCam.c -o openCam `pkg-config --cflags --libs opencv4`

Executar o programa:
./openCam

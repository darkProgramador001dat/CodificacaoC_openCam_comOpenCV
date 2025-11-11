// 1 IMPORTE AS BIBLIOTECAS.
// 2 CRIE UM OBJETO CHAMADO cam, INDICANDO COMO ARGUMENTO 0.
// 3 VERIFICA SE A CÂMERA FOI ABERTA COM SUCESSO, SE NÃO RETORNE UM ERRO.
// 4 DECLARE UM OBJETO CHAMADO frame PARA ARMAZENAR QUADROS DO OpenCV(Imagens, Videos, etc).
// 5 DECLARE UM LAÇO INFINITO.
// 6 UTILIZE O OPERADOR maior 2(duas) vezes PARA CAPTURAR QUADROS E ARMAZENA-LO NO OBJETO frame.
// 7 SE, NÃO A MAS FRAMES PARA CAPTURAR, VERIFIQUE SE ESTÃO LIMPOS E ENCERRE O LAÇO.
// 8 AGORA EXIBA O QUADRO COM O NOME DA JANELA webcam.
// 9 SE, ESPERE POR 30ms PARA FECHAR O PROGRAMA, APONTE PARA CAMERA ASSIM QUE ALGUMA TECLA FOR PRESSIONADA, ENCERRE COM break;
// 10 LIBERE OS RECURSOS ASSOCIADOS A CAMERA.
// 11 FECHE TODAS AS JANELAS DO OPENCV
  
#include <opencv2/opencv.hpp>
#include <stdio.h>

int main()
{
  cv::VideoCapture cam(0);  // argumento 0 representa a camera padrão, se tiver outras pode passar 1, 2, 3, etc.
  
  if(!cam.isOpened())
  {
    printf("Erro: nao foi possivel abrir a camera.\n");
    return -1;  // Se houver um erro, retorne ele.
  }

  cv::Mat frame;  // Criando um objeto que vai receber os quadros do OpenCV.
  
  while(true)  // Laco infinito da janela
  {
    cam >> frame;  // Passando os quadros, e armazenando em frame

    if(frame.empty())break;  // Verifique se estão limpos
    
    cv::imshow("Webcam", frame);  // Criar uma janela com o nome de webcam.
    
    if(cv::waitKey(30) >= 0)break;  // Aponte para a camera, e feche com teclar de qualquer tecla
  }

  cam.release();  // Fechando todos recursos associados ao OpenCV
  
  cv::destroyAllWindows();  // Fechar a janela.
  
  return 0;
}

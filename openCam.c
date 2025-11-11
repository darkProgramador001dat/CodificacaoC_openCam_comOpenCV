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
  cv::VideoCapture cam(0);
  
  if(!cam.isOpened())
  {
    printf("Erro: nao foi possivel abrir a camera.\n");
    return -1;
  }

  cv::Mat frame;
  
  while(true)
  {
    cam >> frame;

    if(frame.empty())break;
    
    cv::imshow("Webcam", frame);
    
    if(cv::waitKey(30) >= 0)break;
  }

  cam.release();
  cv::destroyAllWindows();
  
  return 0;
}

// O programa começa e tenta abrir a webcam.
// Se a webcam for aberta corretamente com sucesso, ele entra em um loop infinito,
// onde captura um frame de vídeo a cada iteração.
// Cada frame capturado é exibido em uma janela chamada "webcam".
// O programa continua exibindo o vídeo até que o usuário tecle qualquer tecla para fechar.

#include <opencv2/opencv.hpp>
#include <stdio.h>

int main()
{
  cv::VideoCapture cam(0); // 0 = /dev/video0
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

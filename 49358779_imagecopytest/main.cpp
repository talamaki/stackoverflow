#include <QApplication>
#include <QLabel>
#include <QImage>
#include <QByteArray>
#include <QBuffer>
#include <stdlib.h>

unsigned char* deepCopyImageData(int &size){
  QImage image("test.png");
  QByteArray bytes;
  QBuffer buffer(&bytes);
  buffer.open(QIODevice::WriteOnly);
  image.save(&buffer, "PNG");
  buffer.close();

  unsigned char *data = (unsigned char *) malloc(bytes.size());
  memcpy(data, reinterpret_cast<unsigned char *>(bytes.data()), bytes.size());
  size = bytes.size();
  return data;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int size;
    unsigned char *data = deepCopyImageData(size);

    QImage image;
    if(!image.loadFromData(data,size))
        qWarning("Image loading failed");

    free(data); data = nullptr;
    QLabel *label = new QLabel();
    label->setPixmap(QPixmap::fromImage(image));
    label->show();

    return a.exec();
}

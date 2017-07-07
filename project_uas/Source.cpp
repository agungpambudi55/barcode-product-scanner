 /*
	Created in July 2017
	Agung Pambudi <agung.pambudi5595@gmail.com>
	Khusnul Danny Rahayu <khusnuldrahayu@gmail.com>
 */
 #include <stdlib.h>  
 #include <opencv2/highgui/highgui.hpp>  
 #include <opencv2/imgproc/imgproc.hpp>  
 #include <zbar.h>  
 #include <cstdio>
 #include <cstdlib>
 #include <mysql.h>
 #include <iostream>  
 using namespace cv;  
 using namespace std;  
 using namespace zbar;  

 // Defining Constant Variables
#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "db_market"

 void product(String data){
	 
 	   if(data == "8998899013015"){
		  system("cls");
		  cout << "Barcode			= " << data << endl;
		  cout << "Nama Barang		= Bayclin Pemutih" << endl;
		  cout << "Merk			= Johnson" << endl;
		  cout << "Berat			= Netto 100 ml" << endl;
		  cout << "Tanggal Produksi	= -" << endl;
		  cout << "Tanggal Kadaluarsa	= -" << endl;
		  cout << "Nama Produsen		= PT Tanshia Customer Products" << endl;
		  cout << "Tempat Produksi		= Jakarta - Indonesia" << endl;
	   }else if(data == "8997209320188"){
		  system("cls");
		  cout << "Barcode			= " << data << endl;
		  cout << "Nama Barang		= Eksotea Original" << endl;
		  cout << "Merk			= Original Taste" << endl;
		  cout << "Berat			= 180 ml" << endl;
		  cout << "Tanggal Produksi	= -" << endl;
		  cout << "Tanggal Kadaluarsa	= Maret 2018" << endl;
		  cout << "Nama Produsen		= PT Startfood Jaya Prima" << endl;
		  cout << "Tempat Produksi		= Kudus - Indonesia" << endl;
		  cout << "Harga			= Rp. 2.000,00 -" << endl;
	   }else if(data == "8992772315128"){
		  system("cls");
		  cout << "Barcode			= " << data << endl;
		  cout << "Nama Barang		= Soffell Botol Kulit Jeruk" << endl;
		  cout << "Merk			= Soffell" << endl;
		  cout << "Berat			= 80 Gr" << endl;
		  cout << "Tanggal Produksi	= -" << endl;
		  cout << "Tanggal Kadaluarsa	= November 2019" << endl;
		  cout << "Nama Produsen		= PT Herlina Indah" << endl;
		  cout << "Tempat Produksi		= Jakarta - Indonesia" << endl;
		  cout << "Harga			= Rp. 17.000,00 -" << endl;
	   }else if(data == "8993482005057"){
		  system("cls");
		  cout << "Barcode			= " << data << endl;
		  cout << "Nama Barang		= Kapur Tulis Bebas Debu Berwarna" << endl;
		  cout << "Merk			= Sarjana" << endl;
		  cout << "Isi			= 50 Batang" << endl;
		  cout << "Tanggal Produksi	= -" << endl;
		  cout << "Tanggal Kadaluarsa	= -" << endl;
		  cout << "Nama Produsen		= PT Indoresco" << endl;
		  cout << "Tempat Produksi		= Bogor - Indonesia" << endl;
		  cout << "Harga			= Rp. 20.000,00 -" << endl;
	   }else if(data == "8992870110144"){
		  system("cls");
		  cout << "Barcode			= " << data << endl;
		  cout << "Nama Barang		= Salonpasgel" << endl;
		  cout << "Merk			= Salonpas" << endl;
		  cout << "Berat			= Netto 15 Gr" << endl;
		  cout << "Tanggal Produksi	= -" << endl;
		  cout << "Tanggal Kadaluarsa	= April 2020" << endl;
		  cout << "Nama Produsen		= PT Hisamitsu Pharma Indonesia" << endl;
		  cout << "Tempat Produksi		= Sidoarjo - Indonesia" << endl;
		  cout << "Harga			= Rp. 15.000,00 -" << endl;
	   }else if(data == "7622210609359"){
		  system("cls");
		  cout << "Barcode			= " << data << endl;
		  cout << "Nama Barang		= Belvita Breakfast Susu dan Sereal" << endl;
		  cout << "Merk			= Belvita" << endl;
		  cout << "Berat			= Netto 20 Gr" << endl;
		  cout << "Tanggal Produksi	= 2 Januari 2017" << endl;
		  cout << "Tanggal Kadaluarsa	= 3 November 2017" << endl;
		  cout << "Nama Produsen		= PT Mondelez Indonesia" << endl;
		  cout << "Tempat Produksi		= Jakarta - Indonesia" << endl;
		  cout << "Harga			= Rp. 23.500,00 -" << endl;
	   }else{
		  system("cls");
	      cout << "Not Found" << endl;
	   }
 }


 int main(int argc, char* argv[]){  

   VideoCapture cap(1);											// open the video camera no. 0  
   if (!cap.isOpened()){  
     cout << "Cannot open camera" << endl;  
     return -1;  
   }  
   ImageScanner scanner;   
   scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);   
   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);			//get the width of frames of the video  
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);			//get the height of frames of the video  
   //cout << "Frame size : " << dWidth << " x " << dHeight << endl;  
   cout << "Barcode Product Scanner" << endl;
   namedWindow("Scan Barcode Product",CV_WINDOW_AUTOSIZE);				//create a window called "Scan Barcode"  
   while(1){  
     Mat frame;  
     bool bSuccess = cap.read(frame);							// read a new frame from video  
      if(!bSuccess){											//if not success, break loop   
        cout << "Cannot read a frame from video stream" << endl;  
        break;  
     }  
     Mat grey;  
     cvtColor(frame,grey,CV_BGR2GRAY);  
     int width = frame.cols;   
     int height = frame.rows;   
     uchar *raw = (uchar *)grey.data;   
     // wrap image data   
     Image image(width, height, "Y800", raw, width * height);   
     // scan the image for barcodes   
     int n = scanner.scan(image);   
     // extract results   
     for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {   
       vector<Point> vp;   
	   // do something useful with results   
	   product(symbol->get_data());
	   //cout  << symbol->get_type_name() << " " << symbol->get_data() << endl;

	   int n = symbol->get_location_size();   
       for(int i=0;i<n;i++){   
         vp.push_back(Point(symbol->get_location_x(i),symbol->get_location_y(i)));   
       }   
       RotatedRect r = minAreaRect(vp);   
       Point2f pts[4];   
       r.points(pts);   
       for(int i=0;i<4;i++){   
         line(frame,pts[i],pts[(i+1)%4],Scalar(255,0,0),3);   
       }   
     }   
     imshow("Scan Barcode Product", frame);							
     if (waitKey(30) == 27){  
       break;   
     }  
   }  
   return 0;  
 }  
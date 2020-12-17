void Traffic_detection()
{
    if(!Traffic_Cascade.load("//home//pi//Desktop//MACHINE LEARNING//Trafficc_cascade.xml"))
    {
	printf("Unable to open traffic cascade file");
    }
    
    RoI_Traffic = frame_Traffic(Rect(200,0,200,140));
    cvtColor(RoI_Traffic, gray_Traffic, COLOR_RGB2GRAY);
    equalizeHist(gray_Traffic, gray_Traffic);
    Traffic_Cascade.detectMultiScale(gray_Traffic, Traffic);
    
    for(int i=0; i<Traffic.size(); i++)
    {
	Point P1(Traffic[i].x, Traffic[i].y);
	Point P2(Traffic[i].x + Traffic[i].width, Traffic[i].y + Traffic[i].height);
	
	rectangle(RoI_Traffic, P1, P2, Scalar(0, 0, 255), 2);
	putText(RoI_Traffic, "Traffic Light", P1, FONT_HERSHEY_PLAIN, 1,  Scalar(0, 0, 255, 255), 2);
	dist_Traffic = (-1.07)*(P2.x-P1.x) + 102.597;
	
       ss.str(" ");
       ss.clear();
       ss<<"D = "<<P2.x-P1.x<<"cm";
       putText(RoI_Traffic, ss.str(), Point2f(1,130), 0,1, Scalar(0,0,255), 2);
	
    }
    
}



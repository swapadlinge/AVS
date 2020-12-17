void Object_detection()
{
    if(!Object_Cascade.load("//home//pi//Desktop//MACHINE LEARNING//Object_cascade.xml"))
    {
	printf("Unable to open Object cascade file");
    }
    
    RoI_Object = frame_Object(Rect(100,50,200,190));
    cvtColor(RoI_Object, gray_Object, COLOR_RGB2GRAY);
    equalizeHist(gray_Object, gray_Object);
    Object_Cascade.detectMultiScale(gray_Object, Object);
    
    for(int i=0; i<Object.size(); i++)
    {
	Point P1(Object[i].x, Object[i].y);
	Point P2(Object[i].x + Object[i].width, Object[i].y + Object[i].height);
	
	rectangle(RoI_Object, P1, P2, Scalar(0, 0, 255), 2);
	putText(RoI_Object, "Object", P1, FONT_HERSHEY_PLAIN, 1,  Scalar(0, 0, 255, 255), 2);
	dist_Object = (-0.48)*(P2.x-P1.x) + 56.6;
	
       ss.str(" ");
       ss.clear();
       ss<<"D = "<<dist_Object<<"cm";
       putText(RoI_Object, ss.str(), Point2f(1,130), 0,1, Scalar(0,0,255), 2);
	
    }
    
}



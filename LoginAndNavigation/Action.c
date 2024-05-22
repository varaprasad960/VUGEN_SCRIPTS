Action()
{
	int nmbr;

	/* Homepage */

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.5");

/*Correlation comment - Do not change!  Original value='138537.912353179HVczAtDpizzzzzzHtcHfzpczDc' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_reg_find("Search=Body",
		"SaveCount=checkpoint",
		"Text=Username",
		LAST);

	lr_start_transaction("WebTour_T01_Homepage");

	web_url("WebTours", 
		"URL=http://192.168.2.109:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	ErrorCode("WebTour_T01_Homepage");

	/* Login */
	
	lr_think_time(10);

	web_reg_find("Search=Body",
		"SaveCount=checkpoint",
		"Text=Welcome",
		LAST);

	lr_start_transaction("WebTour_T02_Login");

	web_submit_data("login.pl",
		"Action=http://192.168.2.109:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://192.168.2.109:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value=jojo", ENDITEM,
		"Name=password", "Value=bean", ENDITEM,
		"Name=login.x", "Value=50", ENDITEM,
		"Name=login.y", "Value=7", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);
	
	nmbr = web_get_int_property(HTTP_INFO_RETURN_CODE);
	
	
	lr_output_message("the response code is: %d", nmbr);

	ErrorCode("WebTour_T02_Login");
	
return 0;
	
	/* Click Flights */
	
	lr_think_time(10);

	web_reg_find("Search=Body",
		"SaveCount=",
		"Text=Departure City",
		LAST);

	lr_start_transaction("WebTour_T03_ClickFlights");

	web_url("Search Flights Button", 
		"URL=http://192.168.2.109:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://192.168.2.109:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

		ErrorCode("WebTour_T03_ClickFlights");


	/* Click Itinerary */
	
	lr_think_time(10);

	web_reg_find("Search=Body",
		"SaveCount=",
		"Text=Itinerary",
		LAST);

	lr_start_transaction("WebTour_T04_ClickItinerary");

	web_url("Itinerary Button",
		"URL=http://192.168.2.109:1080/cgi-bin/welcome.pl?page=itinerary",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://192.168.2.109:1080/cgi-bin/nav.pl?page=menu&in=flights",
		"Snapshot=t4.inf",
		"Mode=HTML",
		LAST);

	ErrorCode("WebTour_T04_ClickItinerary");

	/* Sign Off */

	lr_think_time(10);

	web_reg_find("Search=Body",
		"SaveCount=",
		"Text=Welcome to the Web Tours site",
		LAST);

	lr_start_transaction("WebTour_T05_SignOff");

	web_url("SignOff Button", 
		"URL=http://192.168.2.109:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://192.168.2.109:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

		ErrorCode("WebTour_T05_SignOff");


	return 0;
}
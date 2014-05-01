//Client.h 

#ifdef ClientDll_EXPORTS
#define ClientDLL_API __declspec(dllexport) 
#else
#define ClientDll_API __declspec(dllimport) 
#endif

#include <string>

namespace ClientDll
{

    // This class is exported from the ClientDLL.dll
    class DsauClient
    {
    public:

		//Connect the Client to the Server address in parameter 1
		 static ClientDll_API int mkConnection(std::string ServerAddress);

		//Ends the connection between Server and Client
		 static ClientDll_API int rmConnection();

		//Sends given string to the server
		 static ClientDll_API int sendThis(std::string msgstring);

		//Waits for a response from the server
		static  ClientDll_API int recvThis();

		//Saves response from the server
		static ClientDll_API int saveThis(char* fileSaveName);
    };

}
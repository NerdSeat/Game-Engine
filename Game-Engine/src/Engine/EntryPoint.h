#pragma once
#ifdef GE_PLATFORM_WINDOWS

extern ge::Application* ge::CreateApplication();
int main(int argc, char** argv)
{
	auto app = ge::CreateApplication();
	app->Run();
	delete app;
}


#endif // GE_PLATFORM_WINDOWS


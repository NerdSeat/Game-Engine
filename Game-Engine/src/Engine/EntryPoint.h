#pragma once
#ifdef GE_PLATFORM_WINDOWS

extern ge::Application* ge::CreateApplication();
int main(int argc, char** argv)
{
	ge::Log::Init();
	GE_CORE_WARN("Initialising log");
	int c = 10;
	GE_INFO("Hit the button Var = {0}",c);
	auto app = ge::CreateApplication();
	app->Run();
	delete app;
}


#endif // GE_PLATFORM_WINDOWS


#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <SDL.h>
#include "Scene.h"
class SceneManager {
private:
	/* These are called "forward declarations" The idea is that a pointer is 
	really just an unsigned int, so to create a pointer to it you really only
	need to tell the compiler that there is a class called Window and I need
	a pointer to it, thus the "class Window*" means trust me, there is a class 
	called Window, I just need a pointer to it.

	If that was too much for your brain, just #include "Window.h" and declear
	Window *ptr and don't use the word "class"  This is a second semester C++
	topic anyway */
	class Window *ptr;
	class Timer *timer;
	bool isRunning;
	Scene *currentScene;
public:
	SceneManager();
	~SceneManager();
	bool OnCreate();
	void OnDestroy();
	void HandleEvents();
	void Run();
};
#endif
#ifndef _TEXTURE_
#define _TEXTURE_

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <string>
#include <iostream>
#include <algorithm>

// Lazy work, i didn't want to study filesystem
#define FOLDER "src"



class Texture
{
public:
	unsigned int ID;


	Texture(){
		glGenTextures(1, &ID);
		glBindTexture(GL_TEXTURE_2D, ID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}


	void loadData(const std::string file, int &width, int &height, int &nrChannels)
	{
		unsigned char *data = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);
	}
};
	



#endif
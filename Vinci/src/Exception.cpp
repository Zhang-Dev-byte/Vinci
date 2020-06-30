#include "Exception.h"
#include <sstream>


WException::WException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* WException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* WException::GetType() const noexcept
{
	return "Exception";
}

int WException::GetLine() const noexcept
{
	return line;
}

const std::string& WException::GetFile() const noexcept
{
	return file;
}

std::string WException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}
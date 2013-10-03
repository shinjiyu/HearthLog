#pragma once

#include <wx/filename.h>
#include <wx/config.h>

#include <cstdint>

class Helper
{
public:
	static wxFileName GetUserDataDir();
	static std::uint64_t GetHearthstoneVersion();

	template <typename T> static T ReadConfig(const wxString &key, const T &defaultVal)
	{
		return wxConfig::Get()->Read(key, defaultVal);
	}

	template <typename T> static void WriteConfig(const wxString &key, const T &value)
	{
		auto config = wxConfig::Get();
		config->Write(key, value);
		config->Flush();
	}

private:
	Helper() {}
};


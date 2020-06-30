#pragma once
#include "Win.h"
#include <vector>
#include <wrl.h>
#include <string>
#include <dxgidebug.h>

class DxgiInfoManager
{
public:
	DxgiInfoManager();
	DxgiInfoManager(const DxgiInfoManager&) = delete;
	~DxgiInfoManager() = default;
	DxgiInfoManager& operator=(const DxgiInfoManager&) = delete;
	void Set() noexcept;
	std::vector<std::string> GetMessages() const;
private:
	unsigned long long next = 0u;
	Microsoft::WRL::ComPtr<IDXGIInfoQueue> pDxgiInfoQueue;
};
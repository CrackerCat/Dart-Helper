#pragma once

#include <string>
#include <vector>
#include <map>

class IDAWrapper
{
public:
	//�����������
	static unsigned int get_entry_qty();
	static unsigned int get_entry_ordinal(size_t idx);
	static unsigned int get_entry(size_t order);
	static std::string get_entry_name(size_t order);
	//��ȡname->addr������
	static std::map<std::string, unsigned int> get_entry_map();

	//������������
	//����������һ��ַ,����������������
	static std::vector<unsigned char>read_seg_data(unsigned int addr);
};
#ifndef DIALOG_H
#define DIALOG_H

#include "internal.h"

namespace menu
{
	void dialog(const std::map<const std::string, std::function<void()>> &);
    void dialog(const Option *, int);
    std::string getStr(const std::string &);
}

#endif
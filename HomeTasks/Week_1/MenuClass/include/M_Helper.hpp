//
// Created by Dmitry Morozov on 19/3/23.
//

#ifndef LEVELIP_CPP_JUNIOR_MAIN_HOMETASKS_WEEK_1_MENUCLASS_SRC_M_HELPER_HPP_
#define LEVELIP_CPP_JUNIOR_MAIN_HOMETASKS_WEEK_1_MENUCLASS_SRC_M_HELPER_HPP_

#include <iostream>
#include <any>
#include <string>
#include <variant>
#include <vector>
#include <type_traits>
#include <optional>
#include <sstream>
#include <limits>
#include <cctype>

#ifdef max
#undef max
#endif

inline std::string trim(const std::string &s) {
	constexpr char whitespace[] = " \t\n\r";
	const size_t first = s.find_first_not_of(whitespace);

	return (first!=std::string::npos) ? s.substr(first, (s.find_last_not_of(whitespace) - first + 1)) : std::string{};
}

template<typename T = int>
std::optional<T> stonum(const std::string &st) {
	const auto s = trim(st);
	bool ok = s.empty() ? false : (std::isdigit(s.front())
		|| (((std::is_signed<T>::value && (s.front()=='-')) || (s.front()=='+'))
			&& ((s.size() > 1) && std::isdigit(s[1]))));

	auto v = T{};

	if (ok) {
		std::istringstream ss(s);

		ss >> v;
		ok = (ss.peek()==EOF);
	}

	return ok ? v : std::optional<T>{};
}

std::optional<std::string> getline(std::istream &is, const std::string &def = "") {
	for (auto no = is.rdbuf()->in_avail(); no && is && std::isspace(is.peek()); is.ignore(), --no);

	std::string ln;

	return std::getline(is, ln) ? (ln.empty() && !def.empty() ? def : ln)
								: (is.clear(), std::optional<std::string>{});
}

template<typename T = std::string>
std::optional<T> getdata(std::istream &is) {
	auto i = T{};
	const bool b = (is >> i) && std::isspace(is.peek());

	for (is.clear(); is && !std::isspace(is.peek()); is.ignore());
	return b ? i : std::optional<T>{};
}

template<typename T = int>
auto getnum(std::istream &is, bool wholeline = true) {
	if (wholeline) {
		const auto o = getline(is);
		return o.has_value() ? stonum<T>(*o) : std::optional<T>{};
	}

	return getdata<T>(is);
}

template<typename T = int>
auto getnum(const std::string &prm = "",
			T nmin = std::numeric_limits<T>::lowest(),
			T nmax = std::numeric_limits<T>::max(),
			bool wholeline = true) {
	const auto showdefs = [nmin, nmax]() {
	  std::cout << " (";

	  if (nmin!=std::numeric_limits<T>::lowest() || std::is_unsigned<T>::value)
		  std::cout << nmin;

	  std::cout << " - ";

	  if (nmax!=std::numeric_limits<T>::max())
		  std::cout << nmax;

	  std::cout << ")";
	};

	std::optional<T> o;

	do {
		std::cout << prm;

		if ((nmin!=std::numeric_limits<T>::lowest()) || (nmax!=std::numeric_limits<T>::max()))
			showdefs();

		std::cout << " :";

		o = getnum<T>(std::cin, wholeline);
	} while ((!o.has_value() || (((*o < nmin) || (*o > nmax)))) && (std::cout << "Invalid input" << std::endl));

	return *o;
}

std::optional<char> getchr(std::istream &is, char def = 0, bool wholeline = true) {
	if (wholeline)
		if (auto o = getline(is); o.has_value())
			return (o->empty() && def ? def : ((o->size()==1) ? o->front() : std::optional<char>{}));
		else
			return {};

	return getdata<char>(is);
}

auto getchr(const std::string &prm = "", const std::string &valid = "", char def = 0, bool wholeline = true) {
	const auto showopt = [&valid, def]() {
	  std::cout << " (";

	  for (size_t i = 0, s = valid.size(); i < s; ++i)
		  std::cout << (i ? "/" : "") << valid[i];

	  std::cout << ")";

	  if (def)
		  std::cout << " [" << def << "]";
	};

	std::optional<char> o;

	do {
		std::cout << prm;

		if (!valid.empty())
			showopt();

		std::cout << " :";
		o = getchr(std::cin, def, wholeline);
	} while ((!o.has_value() || ((!valid.empty()) && (valid.find(*o)==std::string::npos)))
		&& (std::cout << "Invalid input" << std::endl));

	return *o;
}

#endif //LEVELIP_CPP_JUNIOR_MAIN_HOMETASKS_WEEK_1_MENUCLASS_SRC_M_HELPER_HPP_

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darknestSecret;

	public:
		void setFirstName(const std::string &str);
		void setLastName(const std::string &str);
		void setNickName(const std::string &str);
		void setPhoneNumber(const std::string &str);
		void setDarknestSecret(const std::string &str);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarknestSecret() const;
} ;

#endif
#include <iostream>
#include <string>
#include <memory>

// Abstract base class for a chatbot.
class Chatbot
{
public:	
	virtual std::string GiveChatResponse() const = 0;
};

// Concrete implementation for a customer service chatbot.
class CustomerServiceChatbot : public Chatbot
{
	std::string GiveChatResponse() const
	{
		return std::string{ "Hello, I am a customer service chatbot" };
	};
};

// Concrete implementation for a feedback service chatbot.
class FeedbackServiceChatbot : public Chatbot
{
	std::string GiveChatResponse() const
	{
		return std::string{ "Hello, I am a feedback service chatbot" };
	};
};

// Factory for creating chatbots
class ChatbotFactory
{
public:
	std::shared_ptr<Chatbot> CreateChatbot(const std::string& ChatbotType)
	{
		if (ChatbotType == "CustomerService")
		{
			return std::make_shared<CustomerServiceChatbot>();
		}
		else if (ChatbotType == "FeedbackService")
		{
			return std::make_shared<FeedbackServiceChatbot>();
		}
	};
};

int main()
{
	std::cout << "1 to talk to Customer service, 2 to give feedback, other to close. \n";
	std::string input;
	std::cin >> input;

	ChatbotFactory factory{};
	std::shared_ptr<Chatbot> chatbot = nullptr;
	if (input == "1")
	{
		chatbot = factory.CreateChatbot("CustomerService");
	}
	else if (input == "2")
	{
		chatbot = factory.CreateChatbot("FeedbackService");
	}
	
	if (chatbot)
		std::cout << chatbot->GiveChatResponse();

	return 0;
}
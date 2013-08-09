-- account table will be account class
Account = 
{
	m_Username = nil;
}
Account.__index = Account
 
-- account class constructor
function Account.Constructor(_Username)
    local self = {}
	
	setmetatable(self, Account)
   
    self.m_Username = _Username
 
    return self
end

function Account:Love()
	return "Love by: " .. self.m_Username
end
  
  
  
  
  
  
-- create a new object
a = Account.Constructor("Tobias Schwandt")

print(a:Love())
 
 
 
 
 
 
 
-- break all references to our object and call the GC
a = nil
collectgarbage()
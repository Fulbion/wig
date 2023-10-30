
grammar wig;

// Keywords in alphabetical order

Break: 'break';
Case: 'case';
Char: 'char';
Class: 'class';
Const: 'const';
Continue : 'continue';
Default: 'default';
Do: 'do';
Else: 'else';
Enum: 'enum';
Float: 'float';
For: 'for';
If: 'if';
Int: 'int';
Mutable: 'mut';
Return: 'return';
Sizeof: 'sizeof';
Struct: 'struct';
Switch: 'switch';
Void: 'void';
While: 'while';

// Operators in alphabetical order
LeftParen: '(';
RightParen: ')';
LeftBracket: '[';
RightBracket: ']';
LeftBrace: '{';
RightBrace: '}';

Less: '<';
LessEqual: '<=';
Greater: '>';
GreaterEqual: '>=';
LeftShift: '<<';
RightShift: '>>';

Plus: '+';
PlusPlus: '++';
Minus: '-';
MinusMinus: '--';
Star: '*';
Div: '/';
Mod: '%';

And: '&';
Or: '|';
AndAnd: '&&';
OrOr: '||';
Caret: '^';
Not: '!';
Tilde: '~';

Question: '?';
Colon: ':';
Semi: ';';
Comma: ',';

Assign: '::';
// '*::' | '/::' | '%::' | '+::' | '-::' | '<<::' | '>>::' | '&::' | '^::' | '|::'
StarAssign: '*::';
DivAssign: '/::';
ModAssign: '%::';
PlusAssign: '+::';
MinusAssign: '-::';
LeftShiftAssign: '<<::';
RightShiftAssign: '>>::';
AndAssign: '&::';
CaretAssign: '^::';
OrAssign: '|::';

Equal: '==';
NotEqual: '!=';

Arrow: '->';
Dot: '.';
Ellipsis: '...';

// Identifiers and literals

Identifier: [a-zA-Z_][a-zA-Z0-9_]*;

IntegerLiteral: [0-9]+;
DecimalLiteral: [0-9]* Dot [0-9]+;
HexadecimalLiteral: '0x' [0-9a-fA-F]+;
CharacterLiteral: '\'' [a-zA-Z0-9_ ] '\'';
StringLiteral: '"' [a-zA-Z0-9_ ]* '"';

// Whitespace and comments

Whitespace: [ \t\r\n]+ -> skip;
LineComment: '//' .*? '\n' -> skip;
BlockComment: '/*' .*? '*/' -> skip;
LineDocComment: '///' .*? '\n' -> skip;
BlockDocComment: '/**' .*? '*/' -> skip;


// Types

// Type: PrimitiveType | PointerType | ArrayType | FunctionType | TupleType | Identifier;

// PrimitiveType: Void | Char | Int | Float;
// ArrayType: Type '[' IntegerLiteral ']';
// PointerType: Type '*';
// FunctionType: Type '(' (Type (',' Type)*)? ')';
// TupleType: '(' (Type (',' Type)*)? ')';

// Disable left recursion

Type: PrimitiveType (PointerType | ArrayType | FunctionType | TupleType)*;

PrimitiveType: Void | Char | Int | Float;
ArrayType: '[' IntegerLiteral ']';
PointerType: Star;
FunctionType: '(' (Type (',' Type)*)? ')';
TupleType: '(' (Type (',' Type)*)? ')';

// Expressions

Expression: AssignmentExpression;

AssignmentExpression: ConditionalExpression (Assign AssignmentExpression)?;

ConditionalExpression: LogicalOrExpression (Question Expression Colon ConditionalExpression)?;

LogicalOrExpression: LogicalAndExpression (OrOr LogicalAndExpression)*;

LogicalAndExpression: InclusiveOrExpression (AndAnd InclusiveOrExpression)*;

InclusiveOrExpression: ExclusiveOrExpression (Or ExclusiveOrExpression)*;

ExclusiveOrExpression: AndExpression (Caret AndExpression)*;

AndExpression: EqualityExpression (And EqualityExpression)*;

EqualityExpression: RelationalExpression ((Equal | NotEqual) RelationalExpression)*;

RelationalExpression: ShiftExpression ((Less | Greater | LessEqual | GreaterEqual) ShiftExpression)*;

ShiftExpression: AdditiveExpression ((LeftShift | RightShift) AdditiveExpression)*;

AdditiveExpression: MultiplicativeExpression ((Plus | Minus) MultiplicativeExpression)*;

MultiplicativeExpression: CastExpression ((Star | Div | Mod) CastExpression)*;

CastExpression: UnaryExpression | '(' Type ')' CastExpression;

UnaryExpression: PostfixExpression | (Plus | Minus | Not | Tilde) UnaryExpression;

PostfixExpression: PrimaryExpression (PostfixOperator)*;

PostfixOperator: LeftParen (Expression (',' Expression)*)? RightParen | LeftBracket Expression RightBracket | Dot Identifier | Arrow Identifier | PlusPlus | MinusMinus;

PrimaryExpression: Identifier | IntegerLiteral | DecimalLiteral | HexadecimalLiteral | CharacterLiteral | StringLiteral | LeftParen Expression RightParen;

// Statements
Statement: ExpressionStatement | CompoundStatement | SelectionStatement | IterationStatement | JumpStatement | Declaration;

ExpressionStatement: Expression ';';
CompoundStatement: '{' (Statement)* '}';
SelectionStatement: IfStatement | SwitchStatement;
IterationStatement: WhileStatement | DoStatement | ForStatement;
JumpStatement: BreakStatement | ContinueStatement | ReturnStatement;

IfStatement: If '(' Expression ')' Statement (Else Statement)?;
SwitchStatement: Switch '(' Expression ')' '{' (Case Expression ':' Statement)* (Default ':' Statement)? '}';

WhileStatement: While '(' Expression ')' Statement;
DoStatement: Do Statement While '(' Expression ')' ';';
ForStatement: For '(' (Expression)? ';' (Expression)? ';' (Expression)? ')' Statement;

BreakStatement: Break ';';
ContinueStatement: Continue ';';
ReturnStatement: Return (Expression)? ';';



// Blocks

Block: '{' (Statement)* '}';

// Declarations

Declaration: VariableDeclaration | ConstantDeclaration | FunctionDeclaration | ClassDeclaration | EnumDeclaration | StructDeclaration;

VariableDeclaration: Mutable? Type Identifier (Assign Expression)? ';';
ConstantDeclaration: Const Type Identifier (Assign Expression)? ';';

FunctionDeclaration: Type Identifier '(' (Type Identifier (',' Type Identifier)*)? ')' Block;
ClassDeclaration: Class Identifier (':' Identifier)? Block;

EnumDeclaration: Enum Identifier Block;
StructDeclaration: Struct Identifier Block;

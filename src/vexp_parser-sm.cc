// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 15 "vexp_parser-sm.y" // lalr1.cc:404

  typedef VExprAst::VExprAstPtr VExprAstPtr;

#line 40 "vexp_parser-sm.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

// //                    "%code requires" blocks.
#line 11 "vexp_parser-sm.y" // lalr1.cc:408

  #include <vexp.h>

#line 55 "vexp_parser-sm.cc" // lalr1.cc:408


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace yy {
#line 130 "vexp_parser-sm.cc" // lalr1.cc:408

  template <class T, class S = std::vector<T> >
  class stack
  {
  public:
    // Hide our reversed order.
    typedef typename S::reverse_iterator iterator;
    typedef typename S::const_reverse_iterator const_iterator;

    stack ()
      : seq_ ()
    {
      seq_.reserve (200);
    }

    stack (unsigned int n)
      : seq_ (n)
    {}

    inline
    T&
    operator[] (unsigned int i)
    {
      return seq_[seq_.size () - 1 - i];
    }

    inline
    const T&
    operator[] (unsigned int i) const
    {
      return seq_[seq_.size () - 1 - i];
    }

    /// Steal the contents of \a t.
    ///
    /// Close to move-semantics.
    inline
    void
    push (T& t)
    {
      seq_.push_back (T());
      operator[](0).move (t);
    }

    inline
    void
    pop (unsigned int n = 1)
    {
      for (; n; --n)
        seq_.pop_back ();
    }

    void
    clear ()
    {
      seq_.clear ();
    }

    inline
    typename S::size_type
    size () const
    {
      return seq_.size ();
    }

    inline
    const_iterator
    begin () const
    {
      return seq_.rbegin ();
    }

    inline
    const_iterator
    end () const
    {
      return seq_.rend ();
    }

  private:
    stack (const stack&);
    stack& operator= (const stack&);
    /// The wrapped container.
    S seq_;
  };

  /// Present a slice of the top of a stack.
  template <class T, class S = stack<T> >
  class slice
  {
  public:
    slice (const S& stack, unsigned int range)
      : stack_ (stack)
      , range_ (range)
    {}

    inline
    const T&
    operator [] (unsigned int i) const
    {
      return stack_[range_ - i];
    }

  private:
    const S& stack_;
    unsigned int range_;
  };

  /// Abstract a position.
  class position
  {
  public:
    /// Construct a position.
    explicit position (std::string* f = YY_NULLPTR,
                       unsigned int l = 1u,
                       unsigned int c = 1u)
      : filename (f)
      , line (l)
      , column (c)
    {
    }


    /// Initialization.
    void initialize (std::string* fn = YY_NULLPTR,
                     unsigned int l = 1u,
                     unsigned int c = 1u)
    {
      filename = fn;
      line = l;
      column = c;
    }

    /** \name Line and Column related manipulators
     ** \{ */
    /// (line related) Advance to the COUNT next lines.
    void lines (int count = 1)
    {
      if (count)
        {
          column = 1u;
          line = add_ (line, count, 1);
        }
    }

    /// (column related) Advance to the COUNT next columns.
    void columns (int count = 1)
    {
      column = add_ (column, count, 1);
    }
    /** \} */

    /// File name to which this position refers.
    std::string* filename;
    /// Current line number.
    unsigned int line;
    /// Current column number.
    unsigned int column;

  private:
    /// Compute max(min, lhs+rhs) (provided min <= lhs).
    static unsigned int add_ (unsigned int lhs, int rhs, unsigned int min)
    {
      return (0 < rhs || -static_cast<unsigned int>(rhs) < lhs
              ? rhs + lhs
              : min);
    }
  };

  /// Add \a width columns, in place.
  inline position&
  operator+= (position& res, int width)
  {
    res.columns (width);
    return res;
  }

  /// Add \a width columns.
  inline position
  operator+ (position res, int width)
  {
    return res += width;
  }

  /// Subtract \a width columns, in place.
  inline position&
  operator-= (position& res, int width)
  {
    return res += -width;
  }

  /// Subtract \a width columns.
  inline position
  operator- (position res, int width)
  {
    return res -= width;
  }

  /// Compare two position objects.
  inline bool
  operator== (const position& pos1, const position& pos2)
  {
    return (pos1.line == pos2.line
            && pos1.column == pos2.column
            && (pos1.filename == pos2.filename
                || (pos1.filename && pos2.filename
                    && *pos1.filename == *pos2.filename)));
  }

  /// Compare two position objects.
  inline bool
  operator!= (const position& pos1, const position& pos2)
  {
    return !(pos1 == pos2);
  }

  /** \brief Intercept output stream redirection.
   ** \param ostr the destination output stream
   ** \param pos a reference to the position to redirect
   */
  template <typename YYChar>
  inline std::basic_ostream<YYChar>&
  operator<< (std::basic_ostream<YYChar>& ostr, const position& pos)
  {
    if (pos.filename)
      ostr << *pos.filename << ':';
    return ostr << pos.line << '.' << pos.column;
  }

  /// Abstract a location.
  class location
  {
  public:

    /// Construct a location from \a b to \a e.
    location (const position& b, const position& e)
      : begin (b)
      , end (e)
    {
    }

    /// Construct a 0-width location in \a p.
    explicit location (const position& p = position ())
      : begin (p)
      , end (p)
    {
    }

    /// Construct a 0-width location in \a f, \a l, \a c.
    explicit location (std::string* f,
                       unsigned int l = 1u,
                       unsigned int c = 1u)
      : begin (f, l, c)
      , end (f, l, c)
    {
    }


    /// Initialization.
    void initialize (std::string* f = YY_NULLPTR,
                     unsigned int l = 1u,
                     unsigned int c = 1u)
    {
      begin.initialize (f, l, c);
      end = begin;
    }

    /** \name Line and Column related manipulators
     ** \{ */
  public:
    /// Reset initial location to final location.
    void step ()
    {
      begin = end;
    }

    /// Extend the current location to the COUNT next columns.
    void columns (int count = 1)
    {
      end += count;
    }

    /// Extend the current location to the COUNT next lines.
    void lines (int count = 1)
    {
      end.lines (count);
    }
    /** \} */


  public:
    /// Beginning of the located region.
    position begin;
    /// End of the located region.
    position end;
  };

  /// Join two locations, in place.
  inline location& operator+= (location& res, const location& end)
  {
    res.end = end.end;
    return res;
  }

  /// Join two locations.
  inline location operator+ (location res, const location& end)
  {
    return res += end;
  }

  /// Add \a width columns to the end position, in place.
  inline location& operator+= (location& res, int width)
  {
    res.columns (width);
    return res;
  }

  /// Add \a width columns to the end position.
  inline location operator+ (location res, int width)
  {
    return res += width;
  }

  /// Subtract \a width columns to the end position, in place.
  inline location& operator-= (location& res, int width)
  {
    return res += -width;
  }

  /// Subtract \a width columns to the end position.
  inline location operator- (location res, int width)
  {
    return res -= width;
  }

  /// Compare two location objects.
  inline bool
  operator== (const location& loc1, const location& loc2)
  {
    return loc1.begin == loc2.begin && loc1.end == loc2.end;
  }

  /// Compare two location objects.
  inline bool
  operator!= (const location& loc1, const location& loc2)
  {
    return !(loc1 == loc2);
  }

  /** \brief Intercept output stream redirection.
   ** \param ostr the destination output stream
   ** \param loc a reference to the location to redirect
   **
   ** Avoid duplicate information.
   */
  template <typename YYChar>
  inline std::basic_ostream<YYChar>&
  operator<< (std::basic_ostream<YYChar>& ostr, const location& loc)
  {
    unsigned int end_col = 0 < loc.end.column ? loc.end.column - 1 : 0;
    ostr << loc.begin;
    if (loc.end.filename
        && (!loc.begin.filename
            || *loc.begin.filename != *loc.end.filename))
      ostr << '-' << loc.end.filename << ':' << loc.end.line << '.' << end_col;
    else if (loc.begin.line < loc.end.line)
      ostr << '-' << loc.end.line << '.' << end_col;
    else if (loc.begin.column < end_col)
      ostr << '-' << end_col;
    return ostr;
  }


  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {}

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;
  };


  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // attribute_instances
      // list_of_attribute_instances
      // attr_specs
      char dummy1[sizeof(Attribute)];

      // expression
      // primary
      // conditional_expression
      // number
      // function_call
      // concatenation
      // multiple_concatenation
      char dummy2[sizeof(VExprAst::VExprAstPtr)];

      // expressions
      char dummy3[sizeof(VExprAst::VExprAstPtrVec)];

      // SIMPLE_ID
      // ESCAPED_ID
      // MACRO_IDENTIFIER
      // NUM_REAL
      // BIN_VALUE
      // HEX_VALUE
      // OCT_VALUE
      // UNSIGNED_NUMBER
      // STRING
      // unsigned_number
      // hierarchical_identifier_special_name
      // text_macro_usage
      // identifier
      // simple_identifier
      // escaped_identifier
      // attr_name
      // string
      char dummy4[sizeof(std::string)];

      // hierarchical_identifier
      char dummy5[sizeof(std::vector<std::string>)];

      // STAR
      // PLUS
      // MINUS
      // ASL
      // ASR
      // LSL
      // LSR
      // DIV
      // POW
      // MOD
      // GTE
      // LTE
      // GT
      // LT
      // L_NEG
      // L_AND
      // L_OR
      // C_EQ
      // L_EQ
      // C_NEQ
      // L_NEQ
      // B_NEG
      // B_AND
      // B_OR
      // B_XOR
      // B_EQU
      // B_NAND
      // B_NOR
      // TERNARY
      // AT
      // unary_operator
      char dummy6[sizeof(voperator)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_STAR = 258,
        TOK_PLUS = 259,
        TOK_MINUS = 260,
        TOK_ASL = 261,
        TOK_ASR = 262,
        TOK_LSL = 263,
        TOK_LSR = 264,
        TOK_DIV = 265,
        TOK_POW = 266,
        TOK_MOD = 267,
        TOK_GTE = 268,
        TOK_LTE = 269,
        TOK_GT = 270,
        TOK_LT = 271,
        TOK_L_NEG = 272,
        TOK_L_AND = 273,
        TOK_L_OR = 274,
        TOK_C_EQ = 275,
        TOK_L_EQ = 276,
        TOK_C_NEQ = 277,
        TOK_L_NEQ = 278,
        TOK_B_NEG = 279,
        TOK_B_AND = 280,
        TOK_B_OR = 281,
        TOK_B_XOR = 282,
        TOK_B_EQU = 283,
        TOK_B_NAND = 284,
        TOK_B_NOR = 285,
        TOK_TERNARY = 286,
        TOK_AT = 287,
        TOK_OPEN_SQ_BRACKET = 288,
        TOK_CLOSE_SQ_BRACKET = 289,
        TOK_OPEN_BRACKET = 290,
        TOK_CLOSE_BRACKET = 291,
        TOK_HASH = 292,
        TOK_OPEN_SQ_BRACE = 293,
        TOK_CLOSE_SQ_BRACE = 294,
        TOK_COMMA = 295,
        TOK_COLON = 296,
        TOK_BIN_BASE = 297,
        TOK_HEX_BASE = 298,
        TOK_OCT_BASE = 299,
        TOK_DEC_BASE = 300,
        TOK_IDX_PRT_SEL_PLUS = 301,
        TOK_IDX_PRT_SEL_MINUS = 302,
        TOK_ATTRIBUTE_START = 303,
        TOK_ATTRIBUTE_END = 304,
        TOK_EQ = 305,
        TOK_DOT = 306,
        TOK_SIMPLE_ID = 307,
        TOK_ESCAPED_ID = 308,
        TOK_MACRO_IDENTIFIER = 309,
        TOK_NUM_REAL = 310,
        TOK_BIN_VALUE = 311,
        TOK_HEX_VALUE = 312,
        TOK_OCT_VALUE = 313,
        TOK_UNSIGNED_NUMBER = 314,
        TOK_STRING = 315
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const Attribute v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const VExprAst::VExprAstPtr v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const VExprAst::VExprAstPtrVec v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::vector<std::string> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const voperator v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_STAR (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_PLUS (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_MINUS (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_ASL (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_ASR (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_LSL (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_LSR (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_DIV (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_POW (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_MOD (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_GTE (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_LTE (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_GT (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_LT (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_L_NEG (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_L_AND (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_L_OR (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_C_EQ (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_L_EQ (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_C_NEQ (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_L_NEQ (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_B_NEG (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_B_AND (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_B_OR (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_B_XOR (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_B_EQU (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_B_NAND (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_B_NOR (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_TERNARY (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_AT (const voperator& v, const location_type& l);

    static inline
    symbol_type
    make_OPEN_SQ_BRACKET (const location_type& l);

    static inline
    symbol_type
    make_CLOSE_SQ_BRACKET (const location_type& l);

    static inline
    symbol_type
    make_OPEN_BRACKET (const location_type& l);

    static inline
    symbol_type
    make_CLOSE_BRACKET (const location_type& l);

    static inline
    symbol_type
    make_HASH (const location_type& l);

    static inline
    symbol_type
    make_OPEN_SQ_BRACE (const location_type& l);

    static inline
    symbol_type
    make_CLOSE_SQ_BRACE (const location_type& l);

    static inline
    symbol_type
    make_COMMA (const location_type& l);

    static inline
    symbol_type
    make_COLON (const location_type& l);

    static inline
    symbol_type
    make_BIN_BASE (const location_type& l);

    static inline
    symbol_type
    make_HEX_BASE (const location_type& l);

    static inline
    symbol_type
    make_OCT_BASE (const location_type& l);

    static inline
    symbol_type
    make_DEC_BASE (const location_type& l);

    static inline
    symbol_type
    make_IDX_PRT_SEL_PLUS (const location_type& l);

    static inline
    symbol_type
    make_IDX_PRT_SEL_MINUS (const location_type& l);

    static inline
    symbol_type
    make_ATTRIBUTE_START (const location_type& l);

    static inline
    symbol_type
    make_ATTRIBUTE_END (const location_type& l);

    static inline
    symbol_type
    make_EQ (const location_type& l);

    static inline
    symbol_type
    make_DOT (const location_type& l);

    static inline
    symbol_type
    make_SIMPLE_ID (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_ESCAPED_ID (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_MACRO_IDENTIFIER (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_NUM_REAL (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_BIN_VALUE (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_HEX_VALUE (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_OCT_VALUE (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_UNSIGNED_NUMBER (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_STRING (const std::string& v, const location_type& l);


    /// Build a parser object.
    parser ();
    virtual ~parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 715,     ///< Last index in yytable_.
      yynnts_ = 23,  ///< Number of nonterminal symbols.
      yyfinal_ = 47, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 61  ///< Number of tokens.
    };


  };

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
    };
    const unsigned int user_token_number_max_ = 315;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 70: // attribute_instances
      case 71: // list_of_attribute_instances
      case 72: // attr_specs
        value.copy< Attribute > (other.value);
        break;

      case 62: // expression
      case 63: // primary
      case 64: // conditional_expression
      case 65: // number
      case 66: // function_call
      case 67: // concatenation
      case 68: // multiple_concatenation
        value.copy< VExprAst::VExprAstPtr > (other.value);
        break;

      case 82: // expressions
        value.copy< VExprAst::VExprAstPtrVec > (other.value);
        break;

      case 52: // SIMPLE_ID
      case 53: // ESCAPED_ID
      case 54: // MACRO_IDENTIFIER
      case 55: // NUM_REAL
      case 56: // BIN_VALUE
      case 57: // HEX_VALUE
      case 58: // OCT_VALUE
      case 59: // UNSIGNED_NUMBER
      case 60: // STRING
      case 73: // unsigned_number
      case 74: // hierarchical_identifier_special_name
      case 75: // text_macro_usage
      case 76: // identifier
      case 77: // simple_identifier
      case 78: // escaped_identifier
      case 79: // attr_name
      case 80: // string
        value.copy< std::string > (other.value);
        break;

      case 81: // hierarchical_identifier
        value.copy< std::vector<std::string> > (other.value);
        break;

      case 3: // STAR
      case 4: // PLUS
      case 5: // MINUS
      case 6: // ASL
      case 7: // ASR
      case 8: // LSL
      case 9: // LSR
      case 10: // DIV
      case 11: // POW
      case 12: // MOD
      case 13: // GTE
      case 14: // LTE
      case 15: // GT
      case 16: // LT
      case 17: // L_NEG
      case 18: // L_AND
      case 19: // L_OR
      case 20: // C_EQ
      case 21: // L_EQ
      case 22: // C_NEQ
      case 23: // L_NEQ
      case 24: // B_NEG
      case 25: // B_AND
      case 26: // B_OR
      case 27: // B_XOR
      case 28: // B_EQU
      case 29: // B_NAND
      case 30: // B_NOR
      case 31: // TERNARY
      case 32: // AT
      case 69: // unary_operator
        value.copy< voperator > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 70: // attribute_instances
      case 71: // list_of_attribute_instances
      case 72: // attr_specs
        value.copy< Attribute > (v);
        break;

      case 62: // expression
      case 63: // primary
      case 64: // conditional_expression
      case 65: // number
      case 66: // function_call
      case 67: // concatenation
      case 68: // multiple_concatenation
        value.copy< VExprAst::VExprAstPtr > (v);
        break;

      case 82: // expressions
        value.copy< VExprAst::VExprAstPtrVec > (v);
        break;

      case 52: // SIMPLE_ID
      case 53: // ESCAPED_ID
      case 54: // MACRO_IDENTIFIER
      case 55: // NUM_REAL
      case 56: // BIN_VALUE
      case 57: // HEX_VALUE
      case 58: // OCT_VALUE
      case 59: // UNSIGNED_NUMBER
      case 60: // STRING
      case 73: // unsigned_number
      case 74: // hierarchical_identifier_special_name
      case 75: // text_macro_usage
      case 76: // identifier
      case 77: // simple_identifier
      case 78: // escaped_identifier
      case 79: // attr_name
      case 80: // string
        value.copy< std::string > (v);
        break;

      case 81: // hierarchical_identifier
        value.copy< std::vector<std::string> > (v);
        break;

      case 3: // STAR
      case 4: // PLUS
      case 5: // MINUS
      case 6: // ASL
      case 7: // ASR
      case 8: // LSL
      case 9: // LSR
      case 10: // DIV
      case 11: // POW
      case 12: // MOD
      case 13: // GTE
      case 14: // LTE
      case 15: // GT
      case 16: // LT
      case 17: // L_NEG
      case 18: // L_AND
      case 19: // L_OR
      case 20: // C_EQ
      case 21: // L_EQ
      case 22: // C_NEQ
      case 23: // L_NEQ
      case 24: // B_NEG
      case 25: // B_AND
      case 26: // B_OR
      case 27: // B_XOR
      case 28: // B_EQU
      case 29: // B_NAND
      case 30: // B_NOR
      case 31: // TERNARY
      case 32: // AT
      case 69: // unary_operator
        value.copy< voperator > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Attribute v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const VExprAst::VExprAstPtr v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const VExprAst::VExprAstPtrVec v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<std::string> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const voperator v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 70: // attribute_instances
      case 71: // list_of_attribute_instances
      case 72: // attr_specs
        value.template destroy< Attribute > ();
        break;

      case 62: // expression
      case 63: // primary
      case 64: // conditional_expression
      case 65: // number
      case 66: // function_call
      case 67: // concatenation
      case 68: // multiple_concatenation
        value.template destroy< VExprAst::VExprAstPtr > ();
        break;

      case 82: // expressions
        value.template destroy< VExprAst::VExprAstPtrVec > ();
        break;

      case 52: // SIMPLE_ID
      case 53: // ESCAPED_ID
      case 54: // MACRO_IDENTIFIER
      case 55: // NUM_REAL
      case 56: // BIN_VALUE
      case 57: // HEX_VALUE
      case 58: // OCT_VALUE
      case 59: // UNSIGNED_NUMBER
      case 60: // STRING
      case 73: // unsigned_number
      case 74: // hierarchical_identifier_special_name
      case 75: // text_macro_usage
      case 76: // identifier
      case 77: // simple_identifier
      case 78: // escaped_identifier
      case 79: // attr_name
      case 80: // string
        value.template destroy< std::string > ();
        break;

      case 81: // hierarchical_identifier
        value.template destroy< std::vector<std::string> > ();
        break;

      case 3: // STAR
      case 4: // PLUS
      case 5: // MINUS
      case 6: // ASL
      case 7: // ASR
      case 8: // LSL
      case 9: // LSR
      case 10: // DIV
      case 11: // POW
      case 12: // MOD
      case 13: // GTE
      case 14: // LTE
      case 15: // GT
      case 16: // LT
      case 17: // L_NEG
      case 18: // L_AND
      case 19: // L_OR
      case 20: // C_EQ
      case 21: // L_EQ
      case 22: // C_NEQ
      case 23: // L_NEQ
      case 24: // B_NEG
      case 25: // B_AND
      case 26: // B_OR
      case 27: // B_XOR
      case 28: // B_EQU
      case 29: // B_NAND
      case 30: // B_NOR
      case 31: // TERNARY
      case 32: // AT
      case 69: // unary_operator
        value.template destroy< voperator > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 70: // attribute_instances
      case 71: // list_of_attribute_instances
      case 72: // attr_specs
        value.move< Attribute > (s.value);
        break;

      case 62: // expression
      case 63: // primary
      case 64: // conditional_expression
      case 65: // number
      case 66: // function_call
      case 67: // concatenation
      case 68: // multiple_concatenation
        value.move< VExprAst::VExprAstPtr > (s.value);
        break;

      case 82: // expressions
        value.move< VExprAst::VExprAstPtrVec > (s.value);
        break;

      case 52: // SIMPLE_ID
      case 53: // ESCAPED_ID
      case 54: // MACRO_IDENTIFIER
      case 55: // NUM_REAL
      case 56: // BIN_VALUE
      case 57: // HEX_VALUE
      case 58: // OCT_VALUE
      case 59: // UNSIGNED_NUMBER
      case 60: // STRING
      case 73: // unsigned_number
      case 74: // hierarchical_identifier_special_name
      case 75: // text_macro_usage
      case 76: // identifier
      case 77: // simple_identifier
      case 78: // escaped_identifier
      case 79: // attr_name
      case 80: // string
        value.move< std::string > (s.value);
        break;

      case 81: // hierarchical_identifier
        value.move< std::vector<std::string> > (s.value);
        break;

      case 3: // STAR
      case 4: // PLUS
      case 5: // MINUS
      case 6: // ASL
      case 7: // ASR
      case 8: // LSL
      case 9: // LSR
      case 10: // DIV
      case 11: // POW
      case 12: // MOD
      case 13: // GTE
      case 14: // LTE
      case 15: // GT
      case 16: // LT
      case 17: // L_NEG
      case 18: // L_AND
      case 19: // L_OR
      case 20: // C_EQ
      case 21: // L_EQ
      case 22: // C_NEQ
      case 23: // L_NEQ
      case 24: // B_NEG
      case 25: // B_AND
      case 26: // B_OR
      case 27: // B_XOR
      case 28: // B_EQU
      case 29: // B_NAND
      case 30: // B_NOR
      case 31: // TERNARY
      case 32: // AT
      case 69: // unary_operator
        value.move< voperator > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }

  inline
  parser::token_type
  parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_STAR (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_STAR, v, l);
  }

  parser::symbol_type
  parser::make_PLUS (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_PLUS, v, l);
  }

  parser::symbol_type
  parser::make_MINUS (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_MINUS, v, l);
  }

  parser::symbol_type
  parser::make_ASL (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_ASL, v, l);
  }

  parser::symbol_type
  parser::make_ASR (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_ASR, v, l);
  }

  parser::symbol_type
  parser::make_LSL (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_LSL, v, l);
  }

  parser::symbol_type
  parser::make_LSR (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_LSR, v, l);
  }

  parser::symbol_type
  parser::make_DIV (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_DIV, v, l);
  }

  parser::symbol_type
  parser::make_POW (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_POW, v, l);
  }

  parser::symbol_type
  parser::make_MOD (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_MOD, v, l);
  }

  parser::symbol_type
  parser::make_GTE (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_GTE, v, l);
  }

  parser::symbol_type
  parser::make_LTE (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_LTE, v, l);
  }

  parser::symbol_type
  parser::make_GT (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_GT, v, l);
  }

  parser::symbol_type
  parser::make_LT (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_LT, v, l);
  }

  parser::symbol_type
  parser::make_L_NEG (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_L_NEG, v, l);
  }

  parser::symbol_type
  parser::make_L_AND (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_L_AND, v, l);
  }

  parser::symbol_type
  parser::make_L_OR (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_L_OR, v, l);
  }

  parser::symbol_type
  parser::make_C_EQ (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_C_EQ, v, l);
  }

  parser::symbol_type
  parser::make_L_EQ (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_L_EQ, v, l);
  }

  parser::symbol_type
  parser::make_C_NEQ (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_C_NEQ, v, l);
  }

  parser::symbol_type
  parser::make_L_NEQ (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_L_NEQ, v, l);
  }

  parser::symbol_type
  parser::make_B_NEG (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_B_NEG, v, l);
  }

  parser::symbol_type
  parser::make_B_AND (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_B_AND, v, l);
  }

  parser::symbol_type
  parser::make_B_OR (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_B_OR, v, l);
  }

  parser::symbol_type
  parser::make_B_XOR (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_B_XOR, v, l);
  }

  parser::symbol_type
  parser::make_B_EQU (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_B_EQU, v, l);
  }

  parser::symbol_type
  parser::make_B_NAND (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_B_NAND, v, l);
  }

  parser::symbol_type
  parser::make_B_NOR (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_B_NOR, v, l);
  }

  parser::symbol_type
  parser::make_TERNARY (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_TERNARY, v, l);
  }

  parser::symbol_type
  parser::make_AT (const voperator& v, const location_type& l)
  {
    return symbol_type (token::TOK_AT, v, l);
  }

  parser::symbol_type
  parser::make_OPEN_SQ_BRACKET (const location_type& l)
  {
    return symbol_type (token::TOK_OPEN_SQ_BRACKET, l);
  }

  parser::symbol_type
  parser::make_CLOSE_SQ_BRACKET (const location_type& l)
  {
    return symbol_type (token::TOK_CLOSE_SQ_BRACKET, l);
  }

  parser::symbol_type
  parser::make_OPEN_BRACKET (const location_type& l)
  {
    return symbol_type (token::TOK_OPEN_BRACKET, l);
  }

  parser::symbol_type
  parser::make_CLOSE_BRACKET (const location_type& l)
  {
    return symbol_type (token::TOK_CLOSE_BRACKET, l);
  }

  parser::symbol_type
  parser::make_HASH (const location_type& l)
  {
    return symbol_type (token::TOK_HASH, l);
  }

  parser::symbol_type
  parser::make_OPEN_SQ_BRACE (const location_type& l)
  {
    return symbol_type (token::TOK_OPEN_SQ_BRACE, l);
  }

  parser::symbol_type
  parser::make_CLOSE_SQ_BRACE (const location_type& l)
  {
    return symbol_type (token::TOK_CLOSE_SQ_BRACE, l);
  }

  parser::symbol_type
  parser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::TOK_COMMA, l);
  }

  parser::symbol_type
  parser::make_COLON (const location_type& l)
  {
    return symbol_type (token::TOK_COLON, l);
  }

  parser::symbol_type
  parser::make_BIN_BASE (const location_type& l)
  {
    return symbol_type (token::TOK_BIN_BASE, l);
  }

  parser::symbol_type
  parser::make_HEX_BASE (const location_type& l)
  {
    return symbol_type (token::TOK_HEX_BASE, l);
  }

  parser::symbol_type
  parser::make_OCT_BASE (const location_type& l)
  {
    return symbol_type (token::TOK_OCT_BASE, l);
  }

  parser::symbol_type
  parser::make_DEC_BASE (const location_type& l)
  {
    return symbol_type (token::TOK_DEC_BASE, l);
  }

  parser::symbol_type
  parser::make_IDX_PRT_SEL_PLUS (const location_type& l)
  {
    return symbol_type (token::TOK_IDX_PRT_SEL_PLUS, l);
  }

  parser::symbol_type
  parser::make_IDX_PRT_SEL_MINUS (const location_type& l)
  {
    return symbol_type (token::TOK_IDX_PRT_SEL_MINUS, l);
  }

  parser::symbol_type
  parser::make_ATTRIBUTE_START (const location_type& l)
  {
    return symbol_type (token::TOK_ATTRIBUTE_START, l);
  }

  parser::symbol_type
  parser::make_ATTRIBUTE_END (const location_type& l)
  {
    return symbol_type (token::TOK_ATTRIBUTE_END, l);
  }

  parser::symbol_type
  parser::make_EQ (const location_type& l)
  {
    return symbol_type (token::TOK_EQ, l);
  }

  parser::symbol_type
  parser::make_DOT (const location_type& l)
  {
    return symbol_type (token::TOK_DOT, l);
  }

  parser::symbol_type
  parser::make_SIMPLE_ID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_SIMPLE_ID, v, l);
  }

  parser::symbol_type
  parser::make_ESCAPED_ID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_ESCAPED_ID, v, l);
  }

  parser::symbol_type
  parser::make_MACRO_IDENTIFIER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_MACRO_IDENTIFIER, v, l);
  }

  parser::symbol_type
  parser::make_NUM_REAL (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_NUM_REAL, v, l);
  }

  parser::symbol_type
  parser::make_BIN_VALUE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_BIN_VALUE, v, l);
  }

  parser::symbol_type
  parser::make_HEX_VALUE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_HEX_VALUE, v, l);
  }

  parser::symbol_type
  parser::make_OCT_VALUE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_OCT_VALUE, v, l);
  }

  parser::symbol_type
  parser::make_UNSIGNED_NUMBER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_UNSIGNED_NUMBER, v, l);
  }

  parser::symbol_type
  parser::make_STRING (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_STRING, v, l);
  }



} // yy
#line 2289 "vexp_parser-sm.cc" // lalr1.cc:408





// User implementation prologue.

#line 2297 "vexp_parser-sm.cc" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 2383 "vexp_parser-sm.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 70: // attribute_instances
      case 71: // list_of_attribute_instances
      case 72: // attr_specs
        value.move< Attribute > (that.value);
        break;

      case 62: // expression
      case 63: // primary
      case 64: // conditional_expression
      case 65: // number
      case 66: // function_call
      case 67: // concatenation
      case 68: // multiple_concatenation
        value.move< VExprAst::VExprAstPtr > (that.value);
        break;

      case 82: // expressions
        value.move< VExprAst::VExprAstPtrVec > (that.value);
        break;

      case 52: // SIMPLE_ID
      case 53: // ESCAPED_ID
      case 54: // MACRO_IDENTIFIER
      case 55: // NUM_REAL
      case 56: // BIN_VALUE
      case 57: // HEX_VALUE
      case 58: // OCT_VALUE
      case 59: // UNSIGNED_NUMBER
      case 60: // STRING
      case 73: // unsigned_number
      case 74: // hierarchical_identifier_special_name
      case 75: // text_macro_usage
      case 76: // identifier
      case 77: // simple_identifier
      case 78: // escaped_identifier
      case 79: // attr_name
      case 80: // string
        value.move< std::string > (that.value);
        break;

      case 81: // hierarchical_identifier
        value.move< std::vector<std::string> > (that.value);
        break;

      case 3: // STAR
      case 4: // PLUS
      case 5: // MINUS
      case 6: // ASL
      case 7: // ASR
      case 8: // LSL
      case 9: // LSR
      case 10: // DIV
      case 11: // POW
      case 12: // MOD
      case 13: // GTE
      case 14: // LTE
      case 15: // GT
      case 16: // LT
      case 17: // L_NEG
      case 18: // L_AND
      case 19: // L_OR
      case 20: // C_EQ
      case 21: // L_EQ
      case 22: // C_NEQ
      case 23: // L_NEQ
      case 24: // B_NEG
      case 25: // B_AND
      case 26: // B_OR
      case 27: // B_XOR
      case 28: // B_EQU
      case 29: // B_NAND
      case 30: // B_NOR
      case 31: // TERNARY
      case 32: // AT
      case 69: // unary_operator
        value.move< voperator > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 70: // attribute_instances
      case 71: // list_of_attribute_instances
      case 72: // attr_specs
        value.copy< Attribute > (that.value);
        break;

      case 62: // expression
      case 63: // primary
      case 64: // conditional_expression
      case 65: // number
      case 66: // function_call
      case 67: // concatenation
      case 68: // multiple_concatenation
        value.copy< VExprAst::VExprAstPtr > (that.value);
        break;

      case 82: // expressions
        value.copy< VExprAst::VExprAstPtrVec > (that.value);
        break;

      case 52: // SIMPLE_ID
      case 53: // ESCAPED_ID
      case 54: // MACRO_IDENTIFIER
      case 55: // NUM_REAL
      case 56: // BIN_VALUE
      case 57: // HEX_VALUE
      case 58: // OCT_VALUE
      case 59: // UNSIGNED_NUMBER
      case 60: // STRING
      case 73: // unsigned_number
      case 74: // hierarchical_identifier_special_name
      case 75: // text_macro_usage
      case 76: // identifier
      case 77: // simple_identifier
      case 78: // escaped_identifier
      case 79: // attr_name
      case 80: // string
        value.copy< std::string > (that.value);
        break;

      case 81: // hierarchical_identifier
        value.copy< std::vector<std::string> > (that.value);
        break;

      case 3: // STAR
      case 4: // PLUS
      case 5: // MINUS
      case 6: // ASL
      case 7: // ASR
      case 8: // LSL
      case 9: // LSR
      case 10: // DIV
      case 11: // POW
      case 12: // MOD
      case 13: // GTE
      case 14: // LTE
      case 15: // GT
      case 16: // LT
      case 17: // L_NEG
      case 18: // L_AND
      case 19: // L_OR
      case 20: // C_EQ
      case 21: // L_EQ
      case 22: // C_NEQ
      case 23: // L_NEQ
      case 24: // B_NEG
      case 25: // B_AND
      case 26: // B_OR
      case 27: // B_XOR
      case 28: // B_EQU
      case 29: // B_NAND
      case 30: // B_NOR
      case 31: // TERNARY
      case 32: // AT
      case 69: // unary_operator
        value.copy< voperator > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 70: // attribute_instances
      case 71: // list_of_attribute_instances
      case 72: // attr_specs
        yylhs.value.build< Attribute > ();
        break;

      case 62: // expression
      case 63: // primary
      case 64: // conditional_expression
      case 65: // number
      case 66: // function_call
      case 67: // concatenation
      case 68: // multiple_concatenation
        yylhs.value.build< VExprAst::VExprAstPtr > ();
        break;

      case 82: // expressions
        yylhs.value.build< VExprAst::VExprAstPtrVec > ();
        break;

      case 52: // SIMPLE_ID
      case 53: // ESCAPED_ID
      case 54: // MACRO_IDENTIFIER
      case 55: // NUM_REAL
      case 56: // BIN_VALUE
      case 57: // HEX_VALUE
      case 58: // OCT_VALUE
      case 59: // UNSIGNED_NUMBER
      case 60: // STRING
      case 73: // unsigned_number
      case 74: // hierarchical_identifier_special_name
      case 75: // text_macro_usage
      case 76: // identifier
      case 77: // simple_identifier
      case 78: // escaped_identifier
      case 79: // attr_name
      case 80: // string
        yylhs.value.build< std::string > ();
        break;

      case 81: // hierarchical_identifier
        yylhs.value.build< std::vector<std::string> > ();
        break;

      case 3: // STAR
      case 4: // PLUS
      case 5: // MINUS
      case 6: // ASL
      case 7: // ASR
      case 8: // LSL
      case 9: // LSR
      case 10: // DIV
      case 11: // POW
      case 12: // MOD
      case 13: // GTE
      case 14: // LTE
      case 15: // GT
      case 16: // LT
      case 17: // L_NEG
      case 18: // L_AND
      case 19: // L_OR
      case 20: // C_EQ
      case 21: // L_EQ
      case 22: // C_NEQ
      case 23: // L_NEQ
      case 24: // B_NEG
      case 25: // B_AND
      case 26: // B_OR
      case 27: // B_XOR
      case 28: // B_EQU
      case 29: // B_NAND
      case 30: // B_NOR
      case 31: // TERNARY
      case 32: // AT
      case 69: // unary_operator
        yylhs.value.build< voperator > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 121 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_expression_primary(yystack_[0].value.as< VExprAst::VExprAstPtr > ());
  }
#line 2992 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 3:
#line 124 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_unary_expression(yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (), AST_FALSE);
  }
#line 3000 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 4:
#line 127 "vexp_parser-sm.y" // lalr1.cc:859
    {
    // this is the A@B shortcut
  }
#line 3008 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 5:
#line 130 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3016 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 6:
#line 133 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3024 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 7:
#line 136 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3032 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 8:
#line 139 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3040 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 9:
#line 142 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3048 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 10:
#line 145 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3056 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 11:
#line 148 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3064 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 12:
#line 151 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3072 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 13:
#line 154 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3080 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 14:
#line 157 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3088 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 15:
#line 160 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3096 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 16:
#line 163 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3104 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 17:
#line 166 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3112 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 18:
#line 169 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3120 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 19:
#line 172 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3128 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 20:
#line 175 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3136 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 21:
#line 178 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3144 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 22:
#line 181 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3152 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 23:
#line 184 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3160 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 24:
#line 187 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3168 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 25:
#line 190 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3176 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 26:
#line 193 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3184 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 27:
#line 196 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3192 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 28:
#line 199 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3200 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 29:
#line 202 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3208 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 30:
#line 205 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_binary_expression(yystack_[3].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< voperator > (),yystack_[1].value.as< Attribute > (),AST_FALSE);
  }
#line 3216 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 31:
#line 208 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< VExprAst::VExprAstPtr > ()=yystack_[0].value.as< VExprAst::VExprAstPtr > ();}
#line 3222 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 32:
#line 210 "vexp_parser-sm.y" // lalr1.cc:859
    {
      yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_primary_function_call(yystack_[0].value.as< VExprAst::VExprAstPtr > ());
  }
#line 3230 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 33:
#line 221 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_conditional_expression(yystack_[5].value.as< VExprAst::VExprAstPtr > (),yystack_[2].value.as< VExprAst::VExprAstPtr > (),yystack_[0].value.as< VExprAst::VExprAstPtr > (),yystack_[3].value.as< Attribute > ());
  }
#line 3238 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 34:
#line 229 "vexp_parser-sm.y" // lalr1.cc:859
    {
      yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_primary(PRIMARY_NUMBER);
      yylhs.value.as< VExprAst::VExprAstPtr > () -> value.number = yystack_[0].value.as< VExprAst::VExprAstPtr > ();
  }
#line 3247 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 35:
#line 233 "vexp_parser-sm.y" // lalr1.cc:859
    {
  
  }
#line 3255 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 36:
#line 236 "vexp_parser-sm.y" // lalr1.cc:859
    {
  
  }
#line 3263 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 37:
#line 239 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_string_expression(yystack_[0].value.as< std::string > ());}
#line 3269 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 38:
#line 240 "vexp_parser-sm.y" // lalr1.cc:859
    {
  // 
}
#line 3277 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 39:
#line 243 "vexp_parser-sm.y" // lalr1.cc:859
    {
      yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_primary(PRIMARY_CONCATENATION);
      yylhs.value.as< VExprAst::VExprAstPtr > () -> value.concatenation = yystack_[0].value.as< VExprAst::VExprAstPtr > ();
  }
#line 3286 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 40:
#line 247 "vexp_parser-sm.y" // lalr1.cc:859
    {
      yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_primary(PRIMARY_CONCATENATION);
      yylhs.value.as< VExprAst::VExprAstPtr > () -> value.concatenation = yystack_[0].value.as< VExprAst::VExprAstPtr > ();
  }
#line 3295 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 41:
#line 251 "vexp_parser-sm.y" // lalr1.cc:859
    {
   // this is also the sub-()
      yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_primary(PRIMARY_MINMAX_EXP);
      yylhs.value.as< VExprAst::VExprAstPtr > () -> value.minmax = yystack_[1].value.as< VExprAst::VExprAstPtr > ();
  }
#line 3305 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 42:
#line 261 "vexp_parser-sm.y" // lalr1.cc:859
    {
  /* this is #a# */
  }
#line 3313 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 43:
#line 270 "vexp_parser-sm.y" // lalr1.cc:859
    {
  }
#line 3320 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 44:
#line 276 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = yystack_[1].value.as< VExprAst::VExprAstPtr > ();
    yylhs.value.as< VExprAst::VExprAstPtr > () -> repeat = yystack_[2].value.as< VExprAst::VExprAstPtr > (); // you need to change this to use REPEAT operator // check here to be constant?
  }
#line 3329 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 45:
#line 284 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_number(BASE_DECIMAL,REP_BITS,yystack_[0].value.as< std::string > ());
  }
#line 3337 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 46:
#line 287 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_number(BASE_BINARY, REP_BITS, yystack_[0].value.as< std::string > ());
}
#line 3345 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 47:
#line 290 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_number(BASE_HEX, REP_BITS, yystack_[0].value.as< std::string > ());
}
#line 3353 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 48:
#line 293 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_number(BASE_OCTAL, REP_BITS, yystack_[0].value.as< std::string > ());
}
#line 3361 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 49:
#line 296 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_number(BASE_DECIMAL, REP_BITS, yystack_[0].value.as< std::string > ());
}
#line 3369 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 50:
#line 299 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_number(BASE_BINARY, REP_BITS, yystack_[0].value.as< std::string > ());
    yylhs.value.as< VExprAst::VExprAstPtr > ()->width = ast_string_to_unsigned_number(yystack_[2].value.as< std::string > ());
}
#line 3378 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 51:
#line 303 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_number(BASE_HEX, REP_BITS, yystack_[0].value.as< std::string > ());
    yylhs.value.as< VExprAst::VExprAstPtr > ()->width = ast_string_to_unsigned_number(yystack_[2].value.as< std::string > ());
}
#line 3387 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 52:
#line 307 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_number(BASE_OCTAL, REP_BITS, yystack_[0].value.as< std::string > ());
    yylhs.value.as< VExprAst::VExprAstPtr > ()->width = ast_string_to_unsigned_number(yystack_[2].value.as< std::string > ());
}
#line 3396 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 53:
#line 311 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_number(BASE_DECIMAL, REP_BITS, yystack_[0].value.as< std::string > ());
    yylhs.value.as< VExprAst::VExprAstPtr > ()->width = ast_string_to_unsigned_number(yystack_[2].value.as< std::string > ());
}
#line 3405 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 54:
#line 315 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< VExprAst::VExprAstPtr > () = yystack_[0].value.as< std::string > ();}
#line 3411 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 55:
#line 320 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< std::string > () = ast_new_number(BASE_DECIMAL, REP_BITS, yystack_[0].value.as< std::string > ());
  }
#line 3419 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 56:
#line 327 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< VExprAst::VExprAstPtr > () = ast_new_function_call(yystack_[4].value.as< std::vector<std::string> > (),AST_FALSE,AST_FALSE,yystack_[3].value.as< Attribute > (),yystack_[1].value.as< VExprAst::VExprAstPtrVec > ());
 }
#line 3427 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 57:
#line 331 "vexp_parser-sm.y" // lalr1.cc:859
    {
   // allow no parameters
 }
#line 3435 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 58:
#line 338 "vexp_parser-sm.y" // lalr1.cc:859
    {
   yylhs.value.as< VExprAst::VExprAstPtrVec > () = VExprAst::VExprAstPtrVec();
   yylhs.value.as< VExprAst::VExprAstPtrVec > ().push_back(yystack_[0].value.as< VExprAst::VExprAstPtr > ());
  }
#line 3444 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 59:
#line 342 "vexp_parser-sm.y" // lalr1.cc:859
    {
  yylhs.value.as< VExprAst::VExprAstPtrVec > () = yystack_[2].value.as< VExprAst::VExprAstPtrVec > ();
  (yylhs.value.as< VExprAst::VExprAstPtrVec > ()).push_back(yystack_[0].value.as< VExprAst::VExprAstPtr > ());
  }
#line 3453 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 60:
#line 351 "vexp_parser-sm.y" // lalr1.cc:859
    {
    // create one and replace as needed
  }
#line 3461 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 61:
#line 354 "vexp_parser-sm.y" // lalr1.cc:859
    {
  }
#line 3468 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 62:
#line 356 "vexp_parser-sm.y" // lalr1.cc:859
    {
  }
#line 3475 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 63:
#line 358 "vexp_parser-sm.y" // lalr1.cc:859
    {
      // $2 $4
  }
#line 3483 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 65:
#line 369 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< Attribute > ()=NULL;}
#line 3489 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 66:
#line 370 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< Attribute > ()=yystack_[0].value.as< Attribute > ();}
#line 3495 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 67:
#line 374 "vexp_parser-sm.y" // lalr1.cc:859
    {
      
  }
#line 3503 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 68:
#line 377 "vexp_parser-sm.y" // lalr1.cc:859
    {

  }
#line 3511 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 69:
#line 382 "vexp_parser-sm.y" // lalr1.cc:859
    { /*make empty one*/ }
#line 3517 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 70:
#line 383 "vexp_parser-sm.y" // lalr1.cc:859
    {
               // make new one
           }
#line 3525 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 71:
#line 386 "vexp_parser-sm.y" // lalr1.cc:859
    {
               // Append the new item to the existing list and return.
           }
#line 3533 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 72:
#line 392 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< std::string > ()=yystack_[0].value.as< std::string > ();}
#line 3539 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 73:
#line 396 "vexp_parser-sm.y" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<std::string> > () = yystack_[0].value.as< std::string > ();
  }
#line 3547 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 74:
#line 399 "vexp_parser-sm.y" // lalr1.cc:859
    {
  // text_macro_usage
      yylhs.value.as< std::vector<std::string> > () = ast_append_identifier(yystack_[2].value.as< std::vector<std::string> > (),yystack_[0].value.as< std::string > ());
  }
#line 3556 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 75:
#line 403 "vexp_parser-sm.y" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<std::string> > () = ast_append_identifier(yystack_[2].value.as< std::vector<std::string> > (),yystack_[0].value.as< std::string > ());
  }
#line 3564 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 76:
#line 412 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< std::string > ()=yystack_[0].value.as< std::string > ();}
#line 3570 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 77:
#line 413 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< std::string > ()=yystack_[0].value.as< std::string > ();}
#line 3576 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 78:
#line 414 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< std::string > ()=yystack_[0].value.as< std::string > ();}
#line 3582 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 79:
#line 418 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< std::string > ()=yystack_[0].value.as< std::string > ();
}
#line 3590 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 80:
#line 425 "vexp_parser-sm.y" // lalr1.cc:859
    {
    yylhs.value.as< std::string > () = VExprAst::MakeVar(yystack_[0].value.as< std::string > ());
}
#line 3598 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 81:
#line 434 "vexp_parser-sm.y" // lalr1.cc:859
    {
  
}
#line 3606 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 82:
#line 442 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< voperator > () = yystack_[0].value.as< voperator > ();}
#line 3612 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 83:
#line 443 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< voperator > () = yystack_[0].value.as< voperator > ();}
#line 3618 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 84:
#line 444 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< voperator > () = yystack_[0].value.as< voperator > ();}
#line 3624 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 85:
#line 445 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< voperator > () = yystack_[0].value.as< voperator > ();}
#line 3630 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 86:
#line 446 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< voperator > () = yystack_[0].value.as< voperator > ();}
#line 3636 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 87:
#line 447 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< voperator > () = yystack_[0].value.as< voperator > ();}
#line 3642 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 88:
#line 448 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< voperator > () = yystack_[0].value.as< voperator > ();}
#line 3648 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 89:
#line 449 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< voperator > () = yystack_[0].value.as< voperator > ();}
#line 3654 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 90:
#line 450 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< voperator > () = yystack_[0].value.as< voperator > ();}
#line 3660 "vexp_parser-sm.cc" // lalr1.cc:859
    break;

  case 91:
#line 451 "vexp_parser-sm.y" // lalr1.cc:859
    {yylhs.value.as< voperator > () = yystack_[0].value.as< voperator > ();}
#line 3666 "vexp_parser-sm.cc" // lalr1.cc:859
    break;


#line 3670 "vexp_parser-sm.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -65;

  const signed char parser::yytable_ninf_ = -66;

  const short int
  parser::yypact_[] =
  {
     118,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   118,   -51,   118,   -52,   -38,   -10,   -39,   -65,   -65,
       2,   -65,   397,    16,   -65,   -65,   -65,   -65,   -65,     3,
     -65,   -65,   -65,   -65,   -30,   363,    15,   327,   -33,   -65,
     -65,   -65,   -65,    -1,    17,    -4,    22,   -65,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,   118,   -65,    38,   655,
     -65,   -43,    21,   -65,   -65,   118,    85,   -65,   118,   -65,
     -65,   -65,   -65,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   176,   -65,   -65,    87,   -65,   -65,   -65,   -65,    88,
      16,    86,   -65,   -65,    -2,   523,   -65,   523,    -3,   629,
     629,    27,    27,    27,    27,    -3,   107,    -3,   122,   122,
     122,   122,   553,    57,   673,   673,   673,   673,   643,   583,
     613,   613,   643,   583,   250,   108,   -65,   118,   118,   118,
       3,   118,   -65,   -24,   118,   427,   459,   491,   -65,   289,
     -65,   523,   -65,   -65,   -65,    38,   -65
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    82,    83,    84,    85,    86,    88,    90,    91,    87,
      89,     0,     0,     0,     0,     0,     0,     0,    80,    45,
      55,    64,     0,     2,    31,    34,    32,    39,    40,    65,
      54,    38,    73,    37,    35,     0,     0,    58,     0,    46,
      47,    48,    49,     0,     0,     0,     0,     1,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,     0,    36,    69,     0,
      66,     0,     0,    41,    42,     0,     0,    43,     0,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    81,     0,    78,    72,    76,    77,     0,
       3,    35,    74,    75,     0,    58,    44,    59,     7,     5,
       6,    30,    29,    28,    27,     8,    16,     9,    20,    18,
      19,    17,    14,    15,    12,    10,    13,    11,    21,    22,
      23,    26,    25,    24,     0,     4,    60,     0,     0,     0,
      67,     0,    57,     0,     0,     0,     0,     0,    68,    70,
      56,    33,    61,    62,    63,    69,    71
  };

  const short int
  parser::yypgoto_[] =
  {
     -65,     0,    62,   -65,   -65,   -65,   112,   -65,   -65,   177,
     -20,   -34,   -65,   -65,   -65,   -65,   -64,    71,   -65,   -65,
      78,    24,   -65
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,   135,    23,    24,    25,    26,    27,    28,    29,    79,
      80,   124,    30,    31,   125,   126,    32,   128,   129,    33,
      34,    38,    77
  };

  const short int
  parser::yytable_[] =
  {
      22,    36,     1,     2,    39,   -65,    87,    88,    56,    18,
     122,    35,   180,    37,   127,     3,    88,   132,    78,    40,
      42,    81,     4,     5,     6,     7,     8,     9,    10,    75,
      48,    49,    50,    11,   172,    12,    13,    55,    56,    57,
      14,    15,    16,    17,    43,    44,    45,    46,    41,    76,
      18,    78,    84,    19,    91,    89,   134,    20,    21,    75,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    90,    62,   121,    64,    65,    66,
      67,    92,    68,    69,    70,    71,    72,    73,   137,    75,
      18,   122,   123,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   127,     1,     2,   136,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     3,   170,    81,   171,    75,
     -66,   130,     4,     5,     6,     7,     8,     9,    10,    86,
     178,   186,   133,    11,    75,    12,    13,   131,   173,     0,
      14,    15,    16,    17,     0,     0,     0,   175,   176,   177,
      18,   179,     0,    19,   181,     0,     0,    20,    21,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,     0,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
     166,    82,     0,     0,     0,     0,     0,   167,     0,     0,
       0,     0,   168,   169,     0,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     0,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,     0,     0,     0,     0,     0,
       0,   174,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,     0,     0,     0,     0,     0,   185,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,     0,     0,     0,    85,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,    47,     0,    83,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,   182,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,   183,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     0,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,   184,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,     0,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,     0,    75,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,     0,    64,    65,    66,    67,     0,    68,     0,
      70,    71,    72,     0,     0,    75,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,    48,    64,    65,    66,    67,     0,    68,    55,
      56,    57,    72,     0,     0,    75,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,    75,     0,    64,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      11,     0,    12,    13,     0,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,    75,     0,    18,     0,     0,
      19,     0,     0,     0,    20,    21
  };

  const short int
  parser::yycheck_[] =
  {
       0,    52,     4,     5,    56,    35,    39,    40,    11,    52,
      53,    11,    36,    13,    78,    17,    40,    81,    48,    57,
      59,    51,    24,    25,    26,    27,    28,    29,    30,    32,
       3,     4,     5,    35,    36,    37,    38,    10,    11,    12,
      42,    43,    44,    45,    42,    43,    44,    45,    58,    33,
      52,    48,    37,    55,    58,    56,    35,    59,    60,    32,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    57,    18,    76,    20,    21,    22,
      23,    59,    25,    26,    27,    28,    29,    30,    88,    32,
      52,    53,    54,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   185,     4,     5,    39,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    17,    49,    51,    50,    32,
      32,    79,    24,    25,    26,    27,    28,    29,    30,    37,
     170,   185,    81,    35,    32,    37,    38,    79,   134,    -1,
      42,    43,    44,    45,    -1,    -1,    -1,   167,   168,   169,
      52,   171,    -1,    55,   174,    -1,    -1,    59,    60,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    34,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    46,    47,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,     0,    -1,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    -1,    32,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    -1,    -1,    32,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,     3,    20,    21,    22,    23,    -1,    25,    10,
      11,    12,    29,    -1,    -1,    32,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    32,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      35,    -1,    37,    38,    -1,    -1,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    32,    -1,    52,    -1,    -1,
      55,    -1,    -1,    -1,    59,    60
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,     5,    17,    24,    25,    26,    27,    28,    29,
      30,    35,    37,    38,    42,    43,    44,    45,    52,    55,
      59,    60,    62,    63,    64,    65,    66,    67,    68,    69,
      73,    74,    77,    80,    81,    62,    52,    62,    82,    56,
      57,    58,    59,    42,    43,    44,    45,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    18,    19,    20,    21,    22,    23,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    83,    48,    70,
      71,    51,    70,    36,    37,    38,    67,    39,    40,    56,
      57,    58,    59,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    62,    53,    54,    72,    75,    76,    77,    78,    79,
      63,    81,    77,    78,    35,    62,    39,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    34,    41,    46,    47,
      49,    50,    36,    82,    41,    62,    62,    62,    71,    62,
      36,    62,    34,    34,    34,    40,    72
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    64,    63,    63,    63,    63,    63,    63,
      63,    63,    74,    67,    68,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    73,    66,    66,    82,    82,
      83,    83,    83,    83,    80,    70,    70,    71,    71,    72,
      72,    72,    79,    81,    81,    81,    76,    76,    76,    78,
      77,    75,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     1,     1,     6,     1,     1,     2,     1,     1,     1,
       1,     3,     3,     3,     4,     1,     2,     2,     2,     2,
       3,     3,     3,     3,     1,     1,     5,     4,     1,     3,
       3,     5,     5,     5,     1,     0,     1,     3,     4,     0,
       3,     5,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "STAR", "PLUS", "MINUS", "ASL", "ASR",
  "LSL", "LSR", "DIV", "POW", "MOD", "GTE", "LTE", "GT", "LT", "L_NEG",
  "L_AND", "L_OR", "C_EQ", "L_EQ", "C_NEQ", "L_NEQ", "B_NEG", "B_AND",
  "B_OR", "B_XOR", "B_EQU", "B_NAND", "B_NOR", "TERNARY", "AT",
  "OPEN_SQ_BRACKET", "CLOSE_SQ_BRACKET", "OPEN_BRACKET", "CLOSE_BRACKET",
  "HASH", "OPEN_SQ_BRACE", "CLOSE_SQ_BRACE", "COMMA", "COLON", "BIN_BASE",
  "HEX_BASE", "OCT_BASE", "DEC_BASE", "IDX_PRT_SEL_PLUS",
  "IDX_PRT_SEL_MINUS", "ATTRIBUTE_START", "ATTRIBUTE_END", "EQ", "DOT",
  "SIMPLE_ID", "ESCAPED_ID", "MACRO_IDENTIFIER", "NUM_REAL", "BIN_VALUE",
  "HEX_VALUE", "OCT_VALUE", "UNSIGNED_NUMBER", "STRING", "$accept",
  "expression", "primary", "conditional_expression", "number",
  "function_call", "concatenation", "multiple_concatenation",
  "unary_operator", "attribute_instances", "list_of_attribute_instances",
  "attr_specs", "unsigned_number", "hierarchical_identifier_special_name",
  "text_macro_usage", "identifier", "simple_identifier",
  "escaped_identifier", "attr_name", "string", "hierarchical_identifier",
  "expressions", "sq_bracket_expression", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   121,   121,   124,   127,   130,   133,   136,   139,   142,
     145,   148,   151,   154,   157,   160,   163,   166,   169,   172,
     175,   178,   181,   184,   187,   190,   193,   196,   199,   202,
     205,   208,   210,   221,   229,   233,   236,   239,   240,   243,
     247,   251,   261,   270,   276,   284,   287,   290,   293,   296,
     299,   303,   307,   311,   315,   320,   326,   330,   338,   342,
     351,   354,   356,   358,   365,   369,   370,   374,   377,   382,
     383,   386,   392,   396,   399,   403,   412,   413,   414,   418,
     425,   434,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 4275 "vexp_parser-sm.cc" // lalr1.cc:1167
#line 455 "vexp_parser-sm.y" // lalr1.cc:1168



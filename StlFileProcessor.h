#ifndef STLFILEPROCESSOR_H
#define STLFILEPROCESSOR_H 1

namespace libstlfile
{

class StlFileProcessor;

}

extern FILE *yyin;

extern int
yyparse(void);

extern void
setStlFileProcessor(libstlfile::StlFileProcessor *newProcessor);

namespace libstlfile
{

typedef double Vec3[3];

class StlFileProcessor
{
public:

  virtual void
  addTriangle(const Vec3 normals,
	      const Vec3 v1,
	      const Vec3 v2,
	      const Vec3 v3) = 0;

  virtual void
  setSolidName(const std::string &name) = 0;

  int
  processFile(const char *fileName)
  {
    yyin = std::fopen(fileName, "r");
    if (!yyin) {
      return errno;
    }
    setStlFileProcessor(this);
    const int result = yyparse();
    fclose(yyin);
    return result;
  }
};

}

#endif // STLFILEPROCESSOR_H

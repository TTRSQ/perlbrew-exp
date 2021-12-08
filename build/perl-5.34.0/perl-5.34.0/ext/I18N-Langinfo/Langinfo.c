/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.43 from the
 * contents of Langinfo.xs. Do not edit this file, edit Langinfo.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Langinfo.xs"
#define PERL_NO_GET_CONTEXT
#define PERL_EXT
#define PERL_EXT_LANGINFO

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#ifdef I_LANGINFO
#   define __USE_GNU 1 /* Enables YESSTR, otherwise only __YESSTR. */
#   include <langinfo.h>
#else
#   include <perl_langinfo.h>
#endif

#include "const-c.inc"

#line 28 "Langinfo.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
	    Perl_croak_nocontext("Usage: %s::%s(%s)", hvname, gvname, params);
        else
	    Perl_croak_nocontext("Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
	Perl_croak_nocontext("Usage: CODE(0x%" UVxf ")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#define croak_xs_usage        S_croak_xs_usage

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#if PERL_VERSION_LE(5, 21, 5)
#  define newXS_deffile(a,b) Perl_newXS(aTHX_ a,b,file)
#else
#  define newXS_deffile(a,b) Perl_newXS_deffile(aTHX_ a,b)
#endif

#line 172 "Langinfo.c"

/* INCLUDE:  Including 'const-xs.inc' from 'Langinfo.xs' */


XS_EUPXS(XS_I18N__Langinfo_AUTOLOAD); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_I18N__Langinfo_AUTOLOAD)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 248 "./const-xs.inc"
	SV *sv = newSVpvn_flags(SvPVX(cv), SvCUR(cv), SVs_TEMP | SvUTF8(cv));
	const COP *cop = PL_curcop;
#line 189 "Langinfo.c"
#line 251 "./const-xs.inc"
#ifndef SYMBIAN
	/* It's not obvious how to calculate this at C pre-processor time.
	   However, any compiler optimiser worth its salt should be able to
	   remove the dead code, and hopefully the now-obviously-unused static
	   function too.  */
	HV *constant_missing = (C_ARRAY_LENGTH(values_for_notfound) > 1)
	    ? get_missing_hash(aTHX) : NULL;
	if ((C_ARRAY_LENGTH(values_for_notfound) > 1)
	    ? hv_exists_ent(constant_missing, sv, 0) : 0) {
	    sv = newSVpvf("Your vendor has not defined I18N::Langinfo macro %" SVf
			  ", used at %" COP_FILE_F " line %" UVuf "\n", 
			  sv, COP_FILE(cop), (UV)CopLINE(cop));
	} else
#endif
	{
	    sv = newSVpvf("%" SVf
                          " is not a valid I18N::Langinfo macro at %"
			  COP_FILE_F " line %" UVuf "\n",
			  sv, COP_FILE(cop), (UV)CopLINE(cop));
	}
	croak_sv(sv_2mortal(sv));
#line 212 "Langinfo.c"
	PUTBACK;
	return;
    }
}


/* INCLUDE: Returning to 'Langinfo.xs' from 'const-xs.inc' */


XS_EUPXS(XS_I18N__Langinfo_langinfo); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_I18N__Langinfo_langinfo)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "code");
    {
	int	code = (int)SvIV(ST(0))
;
#line 28 "Langinfo.xs"
        const   char * value;
        STRLEN  len;
#line 234 "Langinfo.c"
	SV *	RETVAL;
#line 32 "Langinfo.xs"
#ifdef HAS_NL_LANGINFO
	if (code < 0) {
	    SETERRNO(EINVAL, LIB_INVARG);
	    RETVAL = &PL_sv_undef;
	} else
#endif
        {
            value = Perl_langinfo(code);
            len = strlen(value);
            RETVAL = newSVpvn(Perl_langinfo(code), len);

            /* Now see if the UTF-8 flag should be turned on */
#ifdef USE_LOCALE_CTYPE     /* No utf8 strings if not using LC_CTYPE */

            /* If 'value' is ASCII or not legal UTF-8, the flag doesn't get
             * turned on, so skip the followin code */
            if (is_utf8_non_invariant_string((U8 *) value, len)) {
                int category;

                /* Check if the locale is a UTF-8 one.  The returns from
                 * Perl_langinfo() are in different locale categories, so check the
                 * category corresponding to this item */
                switch (code) {

                    /* This should always return ASCII, so we could instead
                     * legitimately panic here, but soldier on */
                    case CODESET:
                        category = LC_CTYPE;
                        break;

                    case RADIXCHAR:
                    case THOUSEP:
#  ifdef USE_LOCALE_NUMERIC
                        category = LC_NUMERIC;
#  else
                        /* Not ideal, but the best we can do on such a platform */
                        category = LC_CTYPE;
#  endif
                        break;

                    case CRNCYSTR:
#  ifdef USE_LOCALE_MONETARY
                        category = LC_MONETARY;
#  else
                        category = LC_CTYPE;
#  endif
                        break;

                    default:
#  ifdef USE_LOCALE_TIME
                        category = LC_TIME;
#  else
                        category = LC_CTYPE;
#  endif
                        break;
                }

                /* Here the return is legal UTF-8.  Turn on that flag if the
                 * locale is UTF-8.  (Otherwise, could just be a coincidence.)
                 * */
                if (_is_cur_LC_category_utf8(category)) {
                    SvUTF8_on(RETVAL);
                }
            }
#endif /* USE_LOCALE_CTYPE */
        }

#line 304 "Langinfo.c"
	RETVAL = sv_2mortal(RETVAL);
	ST(0) = RETVAL;
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_I18N__Langinfo); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_I18N__Langinfo)
{
#if PERL_VERSION_LE(5, 21, 5)
    dVAR; dXSARGS;
#else
    dVAR; dXSBOOTARGSXSAPIVERCHK;
#endif
#if PERL_VERSION_LE(5, 8, 999) /* PERL_VERSION_LT is 5.33+ */
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(file);

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#if PERL_VERSION_LE(5, 21, 5)
    XS_VERSION_BOOTCHECK;
#  ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#  endif
#endif

        newXS_deffile("I18N::Langinfo::AUTOLOAD", XS_I18N__Langinfo_AUTOLOAD);
        (void)newXSproto_portable("I18N::Langinfo::langinfo", XS_I18N__Langinfo_langinfo, file, "_");

    /* Initialisation Section */

#line 2 "./const-xs.inc"
  {
#if defined(dTHX) && !defined(PERL_NO_GET_CONTEXT)
    dTHX;
#endif
    HV *symbol_table = get_hv("I18N::Langinfo::", GV_ADD);

    static const struct iv_s values_for_iv[] =
      {
#ifdef CODESET
        { "CODESET", 7, CODESET },
#endif
#if defined(ABDAY_1) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABDAY_1", 7, ABDAY_1 },
#endif
#if defined(ABDAY_2) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABDAY_2", 7, ABDAY_2 },
#endif
#if defined(ABDAY_3) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABDAY_3", 7, ABDAY_3 },
#endif
#if defined(ABDAY_4) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABDAY_4", 7, ABDAY_4 },
#endif
#if defined(ABDAY_5) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABDAY_5", 7, ABDAY_5 },
#endif
#if defined(ABDAY_6) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABDAY_6", 7, ABDAY_6 },
#endif
#if defined(ABDAY_7) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABDAY_7", 7, ABDAY_7 },
#endif
#if defined(ABMON_1) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_1", 7, ABMON_1 },
#endif
#if defined(ABMON_10) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_10", 8, ABMON_10 },
#endif
#if defined(ABMON_11) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_11", 8, ABMON_11 },
#endif
#if defined(ABMON_12) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_12", 8, ABMON_12 },
#endif
#if defined(ABMON_2) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_2", 7, ABMON_2 },
#endif
#if defined(ABMON_3) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_3", 7, ABMON_3 },
#endif
#if defined(ABMON_4) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_4", 7, ABMON_4 },
#endif
#if defined(ABMON_5) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_5", 7, ABMON_5 },
#endif
#if defined(ABMON_6) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_6", 7, ABMON_6 },
#endif
#if defined(ABMON_7) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_7", 7, ABMON_7 },
#endif
#if defined(ABMON_8) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_8", 7, ABMON_8 },
#endif
#if defined(ABMON_9) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ABMON_9", 7, ABMON_9 },
#endif
#if defined(ALT_DIGITS) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ALT_DIGITS", 10, ALT_DIGITS },
#endif
#if defined(AM_STR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "AM_STR", 6, AM_STR },
#endif
#if defined(DAY_1) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "DAY_1", 5, DAY_1 },
#endif
#if defined(DAY_2) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "DAY_2", 5, DAY_2 },
#endif
#if defined(DAY_3) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "DAY_3", 5, DAY_3 },
#endif
#if defined(DAY_4) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "DAY_4", 5, DAY_4 },
#endif
#if defined(DAY_5) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "DAY_5", 5, DAY_5 },
#endif
#if defined(DAY_6) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "DAY_6", 5, DAY_6 },
#endif
#if defined(DAY_7) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "DAY_7", 5, DAY_7 },
#endif
#if defined(D_FMT) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "D_FMT", 5, D_FMT },
#endif
#if defined(D_T_FMT) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "D_T_FMT", 7, D_T_FMT },
#endif
#if defined(ERA) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ERA", 3, ERA },
#endif
#if defined(ERA_D_FMT) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ERA_D_FMT", 9, ERA_D_FMT },
#endif
#if defined(ERA_D_T_FMT) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ERA_D_T_FMT", 11, ERA_D_T_FMT },
#endif
#if defined(ERA_T_FMT) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "ERA_T_FMT", 9, ERA_T_FMT },
#endif
#if defined(MON_1) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_1", 5, MON_1 },
#endif
#if defined(MON_10) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_10", 6, MON_10 },
#endif
#if defined(MON_11) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_11", 6, MON_11 },
#endif
#if defined(MON_12) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_12", 6, MON_12 },
#endif
#if defined(MON_2) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_2", 5, MON_2 },
#endif
#if defined(MON_3) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_3", 5, MON_3 },
#endif
#if defined(MON_4) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_4", 5, MON_4 },
#endif
#if defined(MON_5) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_5", 5, MON_5 },
#endif
#if defined(MON_6) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_6", 5, MON_6 },
#endif
#if defined(MON_7) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_7", 5, MON_7 },
#endif
#if defined(MON_8) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_8", 5, MON_8 },
#endif
#if defined(MON_9) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "MON_9", 5, MON_9 },
#endif
#if defined(NOEXPR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "NOEXPR", 6, NOEXPR },
#endif
#if defined(NOSTR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "NOSTR", 5, NOSTR },
#endif
#if defined(PM_STR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "PM_STR", 6, PM_STR },
#endif
#if defined(T_FMT) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "T_FMT", 5, T_FMT },
#endif
#if defined(T_FMT_AMPM) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "T_FMT_AMPM", 10, T_FMT_AMPM },
#endif
#if defined(YESEXPR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "YESEXPR", 7, YESEXPR },
#endif
#if defined(YESSTR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM))
        { "YESSTR", 6, YESSTR },
#endif
#if defined(CRNCYSTR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM) && defined(__SVR4_I386_ABI_L1__))
        { "CRNCYSTR", 8, CRNCYSTR },
#endif
#if defined(THOUSEP) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM) && defined(__SVR4_I386_ABI_L1__))
        { "THOUSEP", 7, THOUSEP },
#endif
#if defined(RADIXCHAR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM) && defined(__SVR4_I386_ABI_L1__))
        { "RADIXCHAR", 9, RADIXCHAR },
#endif
        { NULL, 0, 0 } };
	const struct iv_s *value_for_iv = values_for_iv;
        while (value_for_iv->name) {
	    constant_add_symbol(aTHX_  symbol_table, value_for_iv->name,
				value_for_iv->namelen, newSViv(value_for_iv->value));
            ++value_for_iv;
	}
	if (C_ARRAY_LENGTH(values_for_notfound) > 1) {
#ifndef SYMBIAN
	    HV *const constant_missing = get_missing_hash(aTHX);
#endif
	    const struct notfound_s *value_for_notfound = values_for_notfound;
	    do {

		/* Need to add prototypes, else parsing will vary by platform.  */
		HE *he = (HE*) hv_common_key_len(symbol_table,
						 value_for_notfound->name,
						 value_for_notfound->namelen,
						 HV_FETCH_LVALUE, NULL, 0);
		SV *sv;
#ifndef SYMBIAN
		HEK *hek;
#endif
		if (!he) {
		    croak("Couldn't add key '%s' to %%I18N::Langinfo::",
			  value_for_notfound->name);
		}
		sv = HeVAL(he);
		if (!SvOK(sv) && SvTYPE(sv) != SVt_PVGV) {
		    /* Nothing was here before, so mark a prototype of ""  */
		    sv_setpvn(sv, "", 0);
		} else if (SvPOK(sv) && SvCUR(sv) == 0) {
		    /* There is already a prototype of "" - do nothing  */
		} else {
		    /* Someone has been here before us - have to make a real
		       typeglob.  */
		    /* It turns out to be incredibly hard to deal with all the
		       corner cases of sub foo (); and reporting errors correctly,
		       so lets cheat a bit.  Start with a constant subroutine  */
		    CV *cv = newCONSTSUB(symbol_table,
					 value_for_notfound->name,
					 &PL_sv_yes);
		    /* and then turn it into a non constant declaration only.  */
		    SvREFCNT_dec(CvXSUBANY(cv).any_ptr);
		    CvCONST_off(cv);
		    CvXSUB(cv) = NULL;
		    CvXSUBANY(cv).any_ptr = NULL;
		}
#ifndef SYMBIAN
		hek = HeKEY_hek(he);
		if (!hv_common(constant_missing, NULL, HEK_KEY(hek),
 			       HEK_LEN(hek), HEK_FLAGS(hek), HV_FETCH_ISSTORE,
			       &PL_sv_yes, HEK_HASH(hek)))
		    croak("Couldn't add key '%s' to missing_hash",
			  value_for_notfound->name);
#endif
	    } while ((++value_for_notfound)->name);
	}
    /* As we've been creating subroutines, we better invalidate any cached
       methods  */
    mro_method_changed_in(symbol_table);
  }

#line 587 "Langinfo.c"

    /* End of Initialisation Section */

#if PERL_VERSION_LE(5, 21, 5)
#  if PERL_VERSION_GE(5, 9, 0)
    if (PL_unitcheckav)
        call_list(PL_scopestack_ix, PL_unitcheckav);
#  endif
    XSRETURN_YES;
#else
    Perl_xs_boot_epilog(aTHX_ ax);
#endif
}


#!perl

# We are miniperl, building extensions
# Reset @INC completely, adding the directories we need, and removing the
# installed directories (which we don't need to read, and may confuse us)
@INC = (q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/cpan/AutoLoader/lib ,
        q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/dist/Carp/lib ,
        q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/dist/Cwd ,
        q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/dist/Cwd/lib ,
        q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/dist/ExtUtils-Command/lib ,
        q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/dist/ExtUtils-Install/lib ,
        q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/cpan/ExtUtils-MakeMaker/lib ,
        q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/dist/ExtUtils-Manifest/lib ,
        q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/cpan/File-Path/lib ,
        q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/ext/re ,
        q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/dist/Term-ReadLine/lib ,
        q /home/tatsuya.hashimoto/perlbrew/build/perl-5.16.3/perl-5.16.3/lib ,
        q . );
